
var height = 500,
    width = 750;
var fill = d3.scale.category20();

d3.csv("Trump.csv",function(data) {
    var list=data
    .filter(function(d){return +d.Polarity>0; })
    .map(function(d){return {text: d.text,size: +d.Polarity}; });
   
    d3.layout.cloud().size([800, 300])
            .words(data)
            .rotate(function() { return ~~(Math.random() * 2) * 90; })
            .font("Impact")
            .fontSize(function(d) { return d.size; })
            .on("end", drawCloud)
            .start();
});


    function drawCloud(words) {
        d3.select("body").append("svg")
                .attr("width", 850)
                .attr("height", 350)
                .attr("class", "wordcloud")
                .append("g")//avoid being at corner
                // without the transform, words words would get cutoff to the left and top, they would
                // appear outside of the SVG area
                .attr("transform", "translate(320,200)")
                .selectAll("text")
                .data(words)
                .enter().append("text")
                .style("font-family", "Impact")//font
                .style("font-size", function(d) { return d.size + "px"; })
                .style("fill", function(d, i) { return fill(i); })//fill different color
                .attr("text-anchor", "middle")//avoid covering
                .attr("transform", function(d) {
                    return "translate(" + [d.x, d.y] + ")rotate(" + d.rotate + ")";
                })
                .text(function(d) { return d.text; });
    }