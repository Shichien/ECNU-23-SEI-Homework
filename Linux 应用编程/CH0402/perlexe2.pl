#!/usr/bin/perl
use strict;
use warnings;

sub binary_to_decimal {
    my ($binary) = @_;
    return oct("0b$binary");
}

print "请输入一组二进制数（用空格分隔）： ";
my $input = <STDIN>;
chomp($input);

my @binaries = split /\s+/, $input;

my @decimals = ();
foreach my $bin (@binaries) {
    my $dec = binary_to_decimal($bin);
    push @decimals, "$bin => $dec";
}

print "转换结果：\n";
print join("\n", @decimals), "\n";

