document.addEventListener("DOMContentLoaded", () => {
  const sidebar = document.getElementById("sidebar");
  const menuIcon = document.getElementById("menuIcon");
  const closeSidebarBtn = document.getElementById("closeSidebarBtn");
  const content = document.getElementById("content");

  function toggleSidebar() {
    sidebar.style.width = (sidebar.style.width === "250px") ? "0" : "250px";
  }
  menuIcon.addEventListener("click", toggleSidebar);
  closeSidebarBtn.addEventListener("click", toggleSidebar);

  async function loadPage(page) {
    let file = "";
    switch(page) {
      case "main": file = "pages/main.html"; break;
      case "profil": file = "pages/profile.html"; break;
      case "rendeles": file = "pages/order.html"; break;
      case "admin": file = "pages/admin.html"; break;
      default: file = "pages/main.html"; break;
    }

    const resp = await fetch(file);
    const html = await resp.text();
    content.innerHTML = html;

    // futtasd újra a beágyazott scripteket
    const scripts = content.querySelectorAll("script");
    scripts.forEach(oldScript => {
      const newScript = document.createElement("script");
      if (oldScript.src) newScript.src = oldScript.src;
      else newScript.textContent = oldScript.textContent;
      document.body.appendChild(newScript);
    });
  }

  document.querySelectorAll("#sidebar a[data-page]").forEach(link => {
    link.addEventListener("click", e => {
      e.preventDefault();
      const page = link.getAttribute("data-page");
      loadPage(page);
      toggleSidebar();
    });
  });

  loadPage("main");
});