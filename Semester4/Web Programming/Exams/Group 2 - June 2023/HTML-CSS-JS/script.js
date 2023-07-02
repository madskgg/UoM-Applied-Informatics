const pointsElement = document.querySelector(".points");
let totalPoints = 0;

document.getElementById("btnOne").addEventListener("click", function () {
  totalPoints += 1;
  updatePoints();
});

document.getElementById("btnTwo").addEventListener("click", function () {
  totalPoints += 2;
  updatePoints();
});

document.getElementById("btnThree").addEventListener("click", function () {
  totalPoints += 3;
  updatePoints();
});

function updatePoints() {
  pointsElement.textContent = totalPoints;
}
