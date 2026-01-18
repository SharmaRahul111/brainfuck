const root = document.querySelector("div.shell");
const inputBox = root.querySelector("input#focus")
root.height = innerHeight
root.width = innerWidth
// event handling
root.addEventListener("click", () => inputBox.focus())
addEventListener("keypress", (e) => {
  root.innerHTML += e.key
  console.log(e.key, root.innerHTML)
})
