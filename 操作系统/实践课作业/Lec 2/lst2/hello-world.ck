# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(hello-world) begin
Hello, world!
(hello-world) end
EOF
pass;
