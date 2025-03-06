// part 1:

let arr = [
  { name: "apple", count: 5, price: 70 },
  { name: "orange", count: 10, price: 90 },
];

let sum = 0;

for (let i = 0; i < arr.length; i++) {
  sum += arr[i].count * arr[i].price;
}

console.log("price = ", sum);

// part 2:

document.getElementById("copyButton").addEventListener("click", function () {
  const menuItems = document.querySelectorAll("#menu li");
  let menuText = "";

  menuItems.forEach((item) => {
    menuText += item.textContent + " ";
  });

  const paragraph = document.querySelector("#pp");

  if (paragraph) {
    paragraph.textContent += " " + menuText;
  }
});

document.getElementById("colorButton").addEventListener("click", function () {
  const elementsColor = document.querySelectorAll(".myClass");
  elementsColor.forEach((element) => {
    element.style.color = "red";
  });
});
