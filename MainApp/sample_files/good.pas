program moj;

const
	stala1 = 5;
	stala2 = 1.5;
	stala3 = 'abc';

var
	zmienna1 : integer;
	zmienna2 : boolean;
	zmienna3 : string;
	zmienna4 : real;
	i : integer;

function func1 : real;
var
	x : real;
begin
	zmienna1 := 5;
	zmienna3 := 'abc';
	x := zmienna1 + 1.5 / 7;
	
	if x >= 5 then
		func1 := x
	else 
	begin
		x := x/5;
		func1 := x*3;
	end;
end;

function func2 : integer;
var
	x : real;
begin
	zmienna1 := 5;
	zmienna3 := 'abc';
	x := zmienna1 + 1.5 / 7;
	
	if x >= 5 then
		func1 := x
	else 
	begin
		x := x/5;
		func1 := x*3;
	end;
end;

procedure proc1;
const
	s1 = 5;
	s2 = 7;
	s3 = 'dfsfdfgdfgdfgdfhgfjhg';
var
	v1, i : integer;
	v2 : real;
begin
	putline(v1);
	readline(v2);
	v2 := max(v1, v2);
	
	for i := 0 to 20 do
	begin
		v1 := v1+1;
		putline(v1);
	end;
	
	while v2 <= 6.7 do
	begin
		v2 := sin(v1);
		v1 := cos(v2);
		i := v1 + v2;
	end;
	
	putline(s3);
end;

procedure proc2;
const
	s1 = 5;
	s2 = 7;
	s3 = 'dfsfdfgdfgdfgdfhgfjhg';
var
	v1, i : integer;
	v2 : real;
begin
	putline(v1);
	readline(v2);
	v2 := max(v1, v2);
	
	for i := 0 to 20 do
	begin
		v1 := v1+1;
		putline(v1);
	end;
	
	while v2 <= 6.7 do
	begin
		v2 := sin(v1);
		v1 := cos(v2);
		i := v1 + v2;
	end;
	
	putline(s3);
end;

begin
	for i := 100 downto 0 do
	begin
		if (zmienna1 <> 50) and (zmienna3 = 'abc') then
		begin
			putline(i);
			zmienna1 := 67*5/3+7;
		end
		else
		begin
			i := i-1 mod 5;
			zmienna3 := stala1;
		end;
	end;
end.