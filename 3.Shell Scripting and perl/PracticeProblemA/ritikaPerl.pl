use warnings;
use strict;

#question 1
=my $COUNT = 10;
my $stringInput;
my @stringArray;
print("Enter a string to randomize: ");
$stringInput = <STDIN>;
chomp $stringInput;

@stringArray = split(//, $stringInput);

for(my $i = 0;$i<$COUNT;$i++){
	printRandomized(@stringArray);
}
sub printRandomized {
   my (@randArray) = @_;
	my $arraySize = scalar(@randArray);
	for (my $j = $arraySize - 1; $j > 0; $j--){
		my $arrayPos1 = $randArray[$j];
		my $randInt = int(rand($j + 1));
		my $arrayPos2 = $randArray[$randInt];
		$randArray[$randInt] = $arrayPos1;
      $randArray[$j] = $arrayPos2;
   }
	for(my $k = 0; $k < $arraySize; $k++) {
      print($randArray[$k]);
   }
   print("\n");
}
=cut
#question 2
=my @arr;
print "Enter how many strings you want to store:\n ";
my $count = <STDIN>;
while (@arr < $count){
	my $num = <STDIN>;
   chomp $num;
   push @arr, $num;
}
my @res = sort(@arr);

open (fh, ">", "Hello.txt");
for($ct =0;$ct<$count;$ct++){
	print fh "$res[$ct]\n";
}
close(fh) or "Couldn't close the file"; 
=cut
#question 3
=print "Enter the number for which you want factorial:\n";
my $x = <STDIN>;
chomp $x;
print "Factorial of $x using for loop:\t";
$res = 1;
for($i = 1;$i<=$x;$i++){
	$res = $res*$i;
}
print "$res\n";
sub factorial {
    my $n = $_[0];
    return 1 if $n == 0;
    return factorial($n-1)*$n;
}
 
print "Factorial of $x using recursion:\t",factorial($x);
=cut

#question 4

=use List::MoreUtils qw(uniq);
my @list;
print "Enter how many numbers you want to store:\n ";
my $count = <STDIN>;
while (@list < $count){
	my $num = <STDIN>;
   chomp $num;
   push @list, $num;
}
my @uniq_list = uniq(@list);
print "@uniq_list";
=cut
#question 5
=str
$str1 = "RLDVAEWPS GTRTA IEIAI GTVIGTG LTKSSLG";
$str1=~s/ //g;
$str1 =~s/LG/AK/g;
print"${str1}\n";
=cut

#question 6
=my
$date = "31/10/2021";
@dates = split('/',$date);
$temp = $dates[0];
$dates[0] = $dates[1];
$dates[1] = $temp;
print join("/",@dates);
=cut

#queation 7
#udpserver
=str
use IO::Socket::INET;
$| = 1;
my ($socket,$received_data);
my ($peeraddress,$peerport);
$socket = new IO::Socket::INET (LocalPort => '5000',Proto => 'udp')or die "ERROR in Socket Creation : $!\n";

while(1)
{
    $socket->recv($recieved_data,1024);
    $peer_address = $socket->peerhost();
    $peer_port = $socket->peerport();
    print "\n($peer_address , $peer_port) said : $recieved_data";
    $data = "data from server\n";
    print $socket "$data";
}

$socket->close();

#udpclient

use IO::Socket::INET;
$| = 1;
my ($socket,$data);
$socket = new IO::Socket::INET(PeerAddr=>'127.0.0.1:5000',Proto=>'udp')or die "error in socket creation\n";

$data="data from client";
$socket->send($data);
$data = <$socket>;
print "Data received from socket : $data\n";
sleep(10);
$socket->close();

#tcpserver

use IO::Socket::INET;
$| = 1;
my ($socket,$client_socket);
my ($peeraddress,$peerport);
$socket = new IO::Socket::INET (
LocalHost => '127.0.0.1',
LocalPort => '5000',
Proto => 'tcp',
Listen=>5,
Reuse=>1)or die "error in socket creation\n";

print "server waiting fr client connection on port 5000\n";

while(1)
{
    $client_socket = $socket->accept();
    $peer_address = $client_socket->peerhost();
    $peer_port = $client_socket->peerport();
    print "Accepted New Client Connection From : $peeraddress, $peerport\n";
    $data = "DATA from Server";
    print $client_socket "$data\n";
    $data = <$client_socket>;
    print "Received from Client : $data\n";
}

$socket->close();

#tcpclient

use IO::Socket::INET;
$| = 1;
my ($socket,$client_socket);
$socket = new IO::Socket::INET (
PeerHost => '127.0.0.1',PeerPort => '5000',Proto => 'tcp')or die "error in socket creation\n";

print "TCP Connection Success.\n";
$data = <$socket>;
print "Received from Server : $data\n";

$data = "DATA from Client";
print $socket "$data\n";
sleep (10);
$socket->close();

=cut

#end of the program