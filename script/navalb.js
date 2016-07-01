$(function() {

    $.QueryString = (function(a) {
        if (a == "") return {};
        var b = {};
        for (var i = 0; i < a.length; ++i)
        {
            var p=a[i].split('=');
            if (p.length != 2) continue;
            b[p[0]] = decodeURIComponent(p[1].replace(/\+/g, " "));
        }
        return b;
    })(window.location.search.substr(1).split('&'))

    if ($.QueryString["name"] != "player1" && $.QueryString["name"] != "player2") {
      $(".player2-span").text($.QueryString["name"]);
      $(".player-name").show();
      $("#name-input-feelings").hide();
    }

    if ($.QueryString["mode"] && $.QueryString["mode"] > 2)
      $(".name-container > #name-input-feelings").hide();

    $("button.button-dialog:nth-child(2)").click(function() {
      if ($(".Player2-input").val() != "") {
        $(".player2-span").text($(".Player2-input").val());
        $(".player-name").show();
        $("#name-input-feelings").hide();
        $("div.generate-map:nth-child(3) > a:nth-child(1)").attr("href", "?mode=" + $.QueryString["mode"] + "&build=" + $.QueryString["build"] + "&name=" + $("#Player2-input").val());
        window.location.href = "?mode=" + $.QueryString["mode"] + "&build=" + $.QueryString["build"] + "&name=" + $("#Player2-input").val();
      }
    });
});
