document.addEventListener("DOMContentLoaded", () => {
  const toggleButton = document.getElementById("mode");
  const label = document.getElementById("mode-label");
  const icon = toggleButton ? toggleButton.querySelector("i") : null;
  const storageKey = "projet7-theme";
  const themes = { light: "light", dark: "dark" };

  if (!toggleButton || !label) {
    return;
  }

  const storedTheme = localStorage.getItem(storageKey);
  const prefersDark =
    typeof window.matchMedia === "function" &&
    window.matchMedia("(prefers-color-scheme: dark)").matches;
  const initialTheme = storedTheme || (prefersDark ? themes.dark : themes.light);

  applyTheme(initialTheme, true);

  toggleButton.addEventListener("click", () => {
    const nextTheme = document.body.classList.contains("theme-dark")
      ? themes.light
      : themes.dark;

    applyTheme(nextTheme);
  });

  function applyTheme(theme, skipSave = false) {
    const isDark = theme === themes.dark;

    document.body.classList.toggle("theme-dark", isDark);
    label.textContent = isDark ? "Theme clair" : "Theme sombre";

    if (icon) {
      icon.classList.toggle("fa-moon", !isDark);
      icon.classList.toggle("fa-sun", isDark);
    }

    if (!skipSave) {
      localStorage.setItem(storageKey, theme);
    } else if (!storedTheme) {
      localStorage.setItem(storageKey, theme);
    }
  }
});
