const express = require("express");
const app = express();
const mustacheExpress = require("mustache-express");
const PORT = 3000;

// Устанавливаем mustache как шаблонизатор
app.engine("mustache", mustacheExpress());
app.set("view engine", "mustache");
app.set("views", __dirname + "/views");
//

const homeData = require("./data/home.json");

app.get("/", (req, res) => {
  res.render("home", homeData);
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
