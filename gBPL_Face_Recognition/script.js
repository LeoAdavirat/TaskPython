// script.js file

function domReady(fn) {
  if (
    document.readyState === "complete" ||
    document.readyState === "interactive"
  ) {
    setTimeout(fn, 1000);
  } else {
    document.addEventListener("DOMContentLoaded", fn);
  }
}

domReady(function () {
  // If found you qr code
  function onScanSuccess(decodeText, decodeResult) {
    // alert("You Qr is : " + decodeText, decodeResult);
    document.getElementById("display-result").innerHTML =
      "Your Medicine is: " +
      decodeText +
      "<br/>You will take medicines 2 times / 1 days, each after meal (9am and 8pm).";
    document.getElementById("display-result").style.backgroundColor = "white";
    document.getElementById("display-result").style.borderRadius = "20px";
    document.getElementById("display-result").style.boxShadow =
      "0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19)";
  }
  //   background-color: white;
  //     border-radius: 20px;
  //     box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);

  let htmlscanner = new Html5QrcodeScanner("my-qr-reader", {
    fps: 10,
    qrbos: 250,
  });
  htmlscanner.render(onScanSuccess);
});
