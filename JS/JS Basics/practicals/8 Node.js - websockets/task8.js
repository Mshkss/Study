const express = require("express");
const http = require("http");
const { Server } = require("socket.io");

const app = express();
const server = http.createServer(app);
const io = new Server(server);

let sharedText = "";

// Статические файлы (например, index.html)
app.use(express.static(__dirname + "/public"));

io.on("connection", (socket) => {
  console.log("Пользователь подключился:", socket.id);

  socket.emit("init", sharedText); // Отправляем текущее состояние текста при подключении

  socket.on("text-change", (newtext) => {
    sharedText = newtext;
    socket.broadcast.emit("update-text", sharedText);
  });

  socket.on("disconnect", () => {
    console.log("Пользователь отключился:", socket.id);
  });
});

server.listen(3000, () => {
  console.log("Сервер запущен на http://localhost:3000");
});
