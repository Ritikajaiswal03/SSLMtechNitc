use warnings;
use strict;

my @arr;
for(my $i = 0;$i<10;$i++){
	my $x = <STDIN>;
	chomp $x;
	push @arr,$x;
	
}

print "Array = @arr\n";

my @res = sort { $a <=> $b } @arr;

print "Sorted array = @res\n";

my $sum = 0;
for(my $j = 0;$j < 10;$j++){
	$sum = $sum + $arr[$j];
}

print "Sum_of_array = $sum\n";

#question 1

my $n = <STDIN>;
chomp $n;
print "Total Number of tickets:n = $n\n";
my $t = $n - 50;
my $stud = int($t/3);
my $facu = int($t/3);
my $out = int($t/3);

print "No of tickets purchased by the students = $stud\n";
print "No of tickets purchased by the faculties = $facu\n";
print "No of tickets purchased by the outsiders = $out\n";

my $studP = (($stud *100/$n));
my $facuP = (($facu*100)/$n);
my $outP = (($out*100)/$n);

print "Percentage of tickets purchased by the students = $studP","%\n";
print "Percentage of tickets purchased by the faculties = $facuP","%\n";
print "Percentage of tickets purchased by the outsiders = $outP","%\n";
