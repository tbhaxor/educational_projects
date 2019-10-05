// Click Events

// Click event to add a book to the db
$("#addbook").on("click", function() {
  $.ajax({
    type: "POST",
    url: "/submit",
    dataType: "json",
    data: {
      title: $("#title").val(),
      author: $("#author").val(),
      created: Date.now()
    }
  })
  .done(function(data) {
    console.log(data);
    getUnread();
    $("#author").val("");
    $("#title").val("");
  }
  );
  return false;
});

// Click event to mark a book as read
$(document).on("click", ".markread", function() {
  var thisId = $(this).attr("data-id");
  $.ajax({
    type: "GET",
    url: "/markread/" + thisId
  });
  $(this).parents("tr").remove();
  getRead();
});

// Click event to mark a book as not read
$(document).on("click", ".markunread", function() {
  var thisId = $(this).attr("data-id");
  $.ajax({
    type: "GET",
    url: "/markunread/" + thisId
  });
  $(this).parents("tr").remove();
  getUnread();
});


// Functions

// Load unread books and render them to the screen
function getUnread() {
  $("#unread").empty();
  $.getJSON("/unread", function(data) {
    for (var i = 0; i < data.length; i++) {
      $("#unread").prepend("<tr><td>" + data[i].title + "</td><td>" + data[i].author +
        "</td><td><button class='markread' data-id='" + data[i]._id + "'>Mark Read</button></td></tr>");
    }
    $("#unread").prepend("<tr><th>Title</th><th>Author</th><th>Read/Unread</th></tr>");
  });
}

// Load read books and render them to the screen
function getRead() {
  $("#read").empty();
  $.getJSON("/read", function(data) {
    for (var i = 0; i < data.length; i++) {
      $("#read").prepend("<tr><td>" + data[i].title + "</td><td>" + data[i].author +
        "</td><td><button class='markunread' data-id='" + data[i]._id + "'>Mark Unread</button></td></tr>");
    }
    $("#read").prepend("<tr><th>Title</th><th>Author</th><th>Read/Unread</th></tr>");
  });
}

// Calling our functions
getUnread();
getRead();
