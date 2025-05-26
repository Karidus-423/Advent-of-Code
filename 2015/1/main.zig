const std = @import("std");
const debug = std.debug;
const tst = std.testing;

const Result = struct {
    floor: i16,
    idx: i16,
};

fn GetFloor(input: []const u8) Result {
    var res = Result{ .floor = 0, .idx = 0 };
    var idx: i16 = 0;

    for (input) |paren| {
        idx += 1;
        if (paren == '(') {
            res.floor += 1;
        }

        if (paren == ')') {
            res.floor -= 1;
        }

        if (res.floor == -1 and res.idx == 0) {
            res.idx = idx;
        }
    }
    return res;
}

pub fn main() void {
    const input = @embedFile("input.txt");
    const result = GetFloor(input);
    debug.print("FLOOR: {}\n", .{result});
}

test "Part 1" {
    const input: []const u8 = &.{ '(', '(', ')', ')' };
    const result = GetFloor(input);
    try tst.expect(result.floor == 0);
}

test "Part 2" {
    const input: []const u8 = &.{ '(', ')', '(', ')', ')' };
    const result = GetFloor(input);
    try tst.expect(result.idx == 5);
}
