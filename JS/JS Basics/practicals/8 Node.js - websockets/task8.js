const express = require("express");
const mustacheExpress = require("mustache-express");

const app = express();
const PORT = 3000;

// Устанавливаем mustache как шаблонизатор
app.engine("mustache", mustacheExpress());
app.set("view engine", "mustache");
app.set("views", __dirname + "/views");
//
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.send("Привет, это главная страница!");
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
