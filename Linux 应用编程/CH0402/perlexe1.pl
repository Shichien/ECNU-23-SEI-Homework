#!/usr/bin/perl
use strict;
use warnings;

my $filename = $ARGV[0];

open(my $fh, '<', $filename);

my @matched = ();
my @errors = ();
my @stack = ();

my $line_number = 0;

while (my $line = <$fh>) {
    $line_number++;
    my @chars = split //, $line;
    for (my $i = 0; $i < @chars; $i++) {
        if ($chars[$i] eq '(') {
            push @stack, { line => $line_number, pos => $i + 1 };
        } elsif ($chars[$i] eq ')') {
            if (@stack) {
                my $left = pop @stack;
                push @matched, {
                    left_line => $left->{line},
                    left_pos  => $left->{pos},
                    right_line => $line_number,
                    right_pos  => $i + 1
                };
            } else {
                push @errors, { type => 'Unmatched )', line => $line_number, pos => $i + 1 };
            }
        }
    }
}

close($fh);

# 检查是否有未匹配的左括号
while (@stack) {
    my $left = pop @stack;
    push @errors, { type => 'Unmatched (', line => $left->{line}, pos => $left->{pos} };
}

# 输出匹配的括号
if (@matched) {
    print "Matched parentheses:\n";
    foreach my $m (@matched) {
        print "Left '(' at Line $m->{left_line}, Position $m->{left_pos} matched with ')' at Line $m->{right_line}, Position $m->{right_pos}\n";
    }
}

# 输出错误信息
if (@errors) {
    print "\nErrors:\n";
    foreach my $e (@errors) {
        print "$e->{type} at Line $e->{line}, Position $e->{pos}\n";
    }
}
