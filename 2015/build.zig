const std = @import("std");

pub fn build(b: *std.Build) void {
    const d1 = b.addExecutable(.{
        .name = "d1",
        .root_source_file = b.path("1/main.zig"),
        .target = b.graph.host,
    });

    b.installArtifact(d1);

    const run_d1 = b.addRunArtifact(d1);
    const d1_run_step = b.step("d1", "Not Quite Lisp");
    d1_run_step.dependOn(&run_d1.step);
}
