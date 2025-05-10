const express = require("express");
const http = require("http");
const { Server } = require("socket.io");

const app = express();
const server = http.createServer(app);
const io = new Server(server);

// Доступные цвета
const COLORS = ["red", "green", "blue", "orange"];
let freeColors = [...COLORS];

// Храним фрагменты текста с цветами
let sharedFragments = [{ text: "", color: null }];

app.use(express.static(__dirname + "/public"));

io.on("connection", (socket) => {
  // Выдаём цвет
  const myColor = freeColors.shift() || null;
  socket.data.color = myColor;
  socket.emit("set-color", myColor);
  console.log("Пользователь подключился:", socket.id, socket.data.color);
  // Инициализация документа
  socket.emit("init", sharedFragments);

  // Принимаем изменения в виде дельты
  socket.on("text-delta", (delta) => {
    applyDelta(sharedFragments, delta);
    io.emit("init", sharedFragments);
  });

  socket.on("disconnect", () => {
    console.log("Пользователь отключился:", socket.id);
    if (socket.data.color) freeColors.push(socket.data.color);
  });
});

function applyDelta(fragments, { from, removedLength, inserted, color }) {
  let pos = 0;
  for (let i = 0; i < fragments.length; i++) {
    const frag = fragments[i];
    const len = frag.text.length;
    if (pos + len >= from) {
      const offset = from - pos;
      let removeLeft = removedLength;

      // Если вставка/удаление посередине фрагмента — разбиваем фрагмент
      if (offset > 0 && offset < frag.text.length) {
        fragments.splice(i + 1, 0, {
          text: frag.text.slice(offset),
          color: frag.color,
        });
        frag.text = frag.text.slice(0, offset);
      }

      // Если offset равен концу фрагмента, вставляем после него
      let j = i;
      if (offset === frag.text.length) {
        j = i + 1;
      }

      // Удаляем символы из текущего и следующих фрагментов
      while (removeLeft > 0 && j < fragments.length) {
        const fragLen = fragments[j].text.length;
        const canRemove = Math.min(removeLeft, fragLen);
        fragments[j].text = fragments[j].text.slice(canRemove);
        removeLeft -= canRemove;
        if (fragments[j].text.length === 0) {
          fragments.splice(j, 1);
        } else {
          j++;
        }
      }

      // Вставляем новый текст
      if (inserted) {
        fragments.splice(j, 0, { text: inserted, color });
      }

      // Удаляем пустые фрагменты подряд
      for (let k = fragments.length - 1; k >= 0; k--) {
        if (fragments[k].text === "") fragments.splice(k, 1);
      }

      // Если фрагментов не осталось — оставляем один пустой
      if (fragments.length === 0) {
        fragments.push({ text: "", color: null });
      }
      return;
    }
    pos += len;
  }
}

server.listen(3000, () =>
  console.log("Сервер запущен на http://localhost:3000")
);
