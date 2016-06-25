$(function() {
    $("button.button-dialog:nth-child(2)").click(function() {
      if ($("#Player2-input").val() != "") {
        $("#player2-span").text($("#Player2-input").val());
        $(".player-name").show();
        $("#name-input-feelings").hide();
      }
    });
});
