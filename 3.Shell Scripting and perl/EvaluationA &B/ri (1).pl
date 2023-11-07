print "Enter String Size:\n";
$n = <STDIN>;
my @arr;
while (@arr < $n){
	my $num = <STDIN>;
	chomp $num;
	push @arr, $num;
}

my @res = sort(@arr);
print "@res\n";

$ct = 0;
for($i=0; $i<$n;$i++){
	if($arr[$i] eq $res[$i]){
		$ct++;
	}
}
@new_res = lc("@arr");
print "$ct\n";
print "@new_res";

open (fh, ">", "output.txt");
print fh "@res\n";
print fh "$ct\n";
print fh "@new_res\n";

close(fh) or "Couldn't close the file"; 