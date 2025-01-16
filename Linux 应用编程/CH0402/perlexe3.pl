#!/usr/bin/perl
# 注意，需要将每一个可执行的 perl 文件赋予执行权限：
# chmod +x perlexe1.pl perlexe2.pl ...
use strict;
use warnings;

use File::Find;

my @pl_files = grep { -x $_ && /\.pl$/ } glob "*.pl";

my $output_file = "combine.pl";

open(my $out_fh, '>', $output_file) or die "Cannot open '$output_file' for writing: $!";

my $first_shebang = 1;

foreach my $file (@pl_files) {
    open(my $in_fh, '<', $file) or do {
        warn "Cannot open '$file': $!";
        next;
    };

    print $out_fh "# $file combined by perlexe3.pl\n";

    while (my $line = <$in_fh>) {
        if ($first_shebang && $line =~ /^#!/) {
            print $out_fh $line;
            $first_shebang = 0;
            next;
        }
        # Skip other shebang lines
        if (!$first_shebang && $line =~ /^#!/) {
            next;
        }
        print $out_fh $line;
    }

    close($in_fh);
    print $out_fh "\n"; # 添加空行分隔文件
}

close($out_fh);

print "所有可执行的 .pl 文件已合并到 '$output_file'。\n";
