const square = document.querySelector(".square");
const plus10 = document.getElementById("plus10");
const minus10 = document.getElementById("minus10");

let size = 100;

plus10.addEventListener("click", function () {
  if (size < 200) {
    size += 10;
    square.style.width = size + "px";
    square.style.height = size + "px";
    square.innerText = size + "px";
  }
});

minus10.addEventListener("click", function () {
  if (size > 100) {
    size -= 10;
    square.style.width = size + "px";
    square.style.height = size + "px";
    square.innerText = size + "px";
  }
});
