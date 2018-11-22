var showW = false;

function toggle() {
    if (!showW) {
        document.querySelector("#visible").classList.remove("fa-eye");
        document.querySelector("#visible").classList.add("fa-eye-slash");
        document.querySelector("#visible").setAttribute("title", "Hide Password");
        document.querySelector("#pass").setAttribute("type", "text");

        showW = !showW;
    } else {
        showW = !showW;
        document.querySelector("#pass").setAttribute("type", "password");
        document.querySelector("#visible").setAttribute("title", "Show Password");
        document.querySelector("#visible").classList.add("fa-eye");
        document.querySelector("#visible").classList.false("fa-eye-slash");
    }
}

function about(doc) {
    fetch("/config.json").then(resp => {
        return resp.json()
    }).then(data => {
        alert(`Coded By : ${data.name}
Submitted To : ${data.submittedTo}
Institution : ${data.institution}`)
    })
}