var height = 500,
    width = 800;
var Scale= d3.scale.linear().range([10, 100]);
var fill = d3.scale.category20();

var frequency_list = [{"text":"Donald","size":44},{"text":"Trump","size":88},{"text":"Coachella","size":41},{"text":"people","size":43},{"text":"fck","size":55},{"text":"chanting","size":34},{"text":"post","size":41},{"text":"York","size":32},{"text":"YG","size":39},{"text":"Bernie","size":28},{"text":"one","size":28},{"text":"thankful","size":13},{"text":"Glow","size":13},{"text":"Basks","size":13},{"text":"CHANGE","size":13},{"text":"nominee","size":13},{"text":"latest","size":13},{"text":"face","size":13},{"text":"Bank","size":13},{"text":"Weat","size":13},{"text":"Help","size":13},{"text":"Seeks","size":13},{"text":"angry","size":13},{"text":"Never","size":13},{"text":"National","size":13},{"text":"Fallon","size":13},{"text":"kelly","size":13},{"text":"DumpTrump","size":13},{"text":"Brendon","size":13},{"text":"corrupt","size":13},{"text":"Hilary","size":13},{"text":"AMERICAN","size":13},{"text":"Sucks","size":13},{"text":"Colorado","size":13},{"text":"Took","size":13},{"text":"CruzCrew","size":13},{"text":"Youre","size":14},{"text":"Acid","size":14},{"text":"STONE","size":14},{"text":"SHARON","size":14},{"text":"entrepreneur","size":14},{"text":"border","size":14},{"text":"DemDebate","size":15},{"text":"Tower","size":14},{"text":"chance","size":14},{"text":"hussle","size":14},{"text":"Bills","size":14},{"text":"plaintalking","size":14},{"text":"MAGA","size":14},{"text":"RAPPER","size":14},{"text":"nipsey","size":14},{"text":"BREAKING","size":14},{"text":"roasting","size":14},{"text":"NeverTrump","size":14},{"text":"Trade","size":14},{"text":"Barbs","size":14},{"text":"commonsense","size":14},{"text":"outerborough","size":14},{"text":"NYpost","size":14},{"text":"sensibilities","size":14},{"text":"Wives","size":14},{"text":"loser","size":14},{"text":"MelaniaTrump","size":14},{"text":"trumptrain","size":15},{"text":"journalnever","size":15},{"text":"Ryan","size":15},{"text":"Miller","size":15},{"text":"MakeAmericaGreatAgain","size":16},{"text":"delegate","size":16},{"text":"Jewish","size":16},{"text":"money","size":17},{"text":"Republicans","size":17},{"text":"Clinton","size":18},{"text":"Candidate","size":18},{"text":"stupid","size":18},{"text":"Republican","size":19},{"text":"NYPrimary","size":19},{"text":"Sanders","size":24},{"text":"campaign","size":20},{"text":"makeup","size":19},{"text":"endorses","size":20},{"text":"drops","size":13},{"text":"Hate","size":14},{"text":"values","size":16},{"text":"WHITE","size":18},{"text":"Joe","size":13},{"text":"work","size":13},{"text":"shit","size":13},{"text":"mood","size":13},{"text":"ASS","size":13},{"text":"2016","size":13},{"text":"CNN","size":14},{"text":"GREAT","size":19},{"text":"Trump2016","size":22},{"text":"President","size":22},{"text":"Trumps","size":23},{"text":"Rex","size":42},{"text":"LOL","size":14},{"text":"MAN","size":14},{"text":"war","size":14},{"text":"911","size":14},{"text":"win","size":16},{"text":"Poll","size":15},{"text":"Fox","size":16},{"text":"Guy","size":87},{"text":"best","size":17},{"text":"GOP","size":17},{"text":"CAKE","size":18},{"text":"HANG","size":18},{"text":"VOTE","size":19},{"text":"wear","size":19},{"text":"NY","size":20},{"text":"FAKE","size":21},{"text":"America","size":21},{"text":"Hillary","size":22},{"text":"Fuck","size":26},{"text":"Ted","size":24},{"text":"Cruz","size":26},{"text":"vs","size":28},{"text":"New","size":36},{"text":"vs","size":28},{"text":"rally","size":38},{"text":"FCK","size":38}];
Scale.domain([d3.min(frequency_list,function(d){return d.size;}),
    d3.max(frequency_list,function(d){return d.size;})
    ]);

d3.layout.cloud().size([width, height])
            .words(frequency_list
                .slice(0,500))
            .padding(2)
            //.rotate(function() { return ~~(Math.random() * 2) * 90; })
            .font("Impact")
            .fontSize(function(d) { return Scale(d.size); })
            .on("end", drawCloud)
            .start();

    function drawCloud(words) {
        d3.select("body").append("svg")
                .attr("width", width)
                .attr("height", height)
                .attr("class", "wordcloud")
                .append("g")//avoid being at corner
                // without the transform, words words would get cutoff to the left and top, they would
                // appear outside of the SVG area
                .attr("transform", "translate("+width/2+","+height/2+")")
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