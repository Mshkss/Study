const express = require("express");
const mustacheExpress = require("mustache-express");

const app = express();
const PORT = 3000;

// Устанавливаем mustache как шаблонизатор
app.engine("mustache", mustacheExpress());
app.set("view engine", "mustache");
app.set("views", __dirname + "/views");
//
app.use(express.urlencoded({ extended: true })); // типо боди парсер

const homeData = require("./data/home.json");
app.get("/", (req, res) => {
  res.render("home", homeData);
});

const aboutData = require("./data/about.json");
app.get("/about", (req, res) => {
  res.render("about", aboutData);
});

const contactData = require("./data/contact.json");
app.get("/contact", (req, res) => {
  res.render("contact", contactData);
});

//reg
app.get("/reg", (req, res) => {
  res.render("reg");
});

app.post("/submit", (req, res) => {
  const regData = req.body;
  console.log(regData); // Для отладки, можно удалить позже
  const listData = Object.entries(regData).map(([key, value]) => {
    return { field: key, value };
  });

  res.render("result", { list: listData });
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
