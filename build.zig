const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});

    const optimize = b.standardOptimizeOption(.{});

    var targets = std.ArrayList(*std.Build.CompileStep).init(b.allocator);

    const lib = b.addStaticLibrary(.{
        .name = "libtui",
        .version = .{ .major = 1, .minor = 0, .patch = 0 },
        .target = target,
        .optimize = optimize,
    });

    var flags = &.{
        "-std=c99",
        "-Wextra",
        "-Wall",
        "-Wfloat-equal",
        "-Wundef",
        "-Wshadow",
        "-Wpointer-arith",
        "-Wcast-align",
        "-Wstrict-prototypes",
        "-Wstrict-prototypes",
        "-Wwrite-strings",
        "-Waggregate-return",
        "-Wcast-qual",
        "-Werror",
        "-Winit-self",
        "-Wno-error=unused-command-line-argument",
        "-O1",
        "-fsanitize-address-use-after-scope",
        "-fsanitize-address-use-odr-indicator",
        "-fsanitize-memory-use-after-dtor",
        "-fno-omit-frame-pointer",
        "-fstack-protector-strong",
    };

    lib.linkLibC();
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_buffer.c",
        },
        .flags = flags,
    });
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_renderer.c",
        },
        .flags = flags,
    });
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_draw.c",
        },
        .flags = flags,
    });
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_keyboard.c",
        },
        .flags = flags,
    });
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_term_control.c",
        },
        .flags = flags,
    });
    targets.append(lib) catch @panic("OOM");

    const example_exe = b.addExecutable(.{
        .name = "example",
        .root_source_file = .{ .path = "examples/simple.c" },
        .target = target,
        .optimize = optimize,
    });

    example_exe.addIncludePath(.{
        .path = "lib",
    });
    example_exe.linkLibC();
    example_exe.linkLibrary(lib);

    targets.append(example_exe) catch @panic("OOM");

    b.installArtifact(example_exe);

    const run_cmd = b.addRunArtifact(example_exe);

    run_cmd.step.dependOn(b.getInstallStep());

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
