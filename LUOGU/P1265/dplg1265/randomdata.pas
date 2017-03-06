program dp;
var a,b,c,i:longint;
begin
    randomize;
    repeat a:=random(1000)+1; until a<>1;
    writeln(a);
    for i:=1 to a do begin
        b:=(random(20000)+1) mod 10;
        c:=(random(20000)+1) mod 10;
        writeln(b,' ',c);
    end;
end.
