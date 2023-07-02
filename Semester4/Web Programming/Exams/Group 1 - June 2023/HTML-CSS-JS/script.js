const square = document.getElementById("square");
const butt1 = document.getElementById("butt1");
const butt2 = document.getElementById("butt2");
const butt3 = document.getElementById("butt3");
const butt4 = document.getElementById("butt4");

butt1.addEventListener("click", function () {
  square.classList.toggle("corner-top-left");
});

butt2.addEventListener("click", function () {
  square.classList.toggle("corner-bottom-left");
});

butt3.addEventListener("click", function () {
  square.classList.toggle("corner-top-right");
});

butt4.addEventListener("click", function () {
  square.classList.toggle("corner-bottom-right");
});
