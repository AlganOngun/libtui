const std = @import("std");
const zcc = @import("compile_commands");

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
            .path = "lib/libtui_buffering.c",
        },
        .flags = flags,
    });
    lib.addCSourceFile(.{
        .file = .{
            .path = "lib/libtui_error.c",
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

    const client_exe = b.addExecutable(.{
        .name = "client",
        .root_source_file = .{ .path = "client/main.c" },
        .target = target,
        .optimize = optimize,
    });

    client_exe.addIncludePath(.{
        .path = "lib",
    });
    client_exe.linkLibC();
    client_exe.linkLibrary(lib);

    targets.append(client_exe) catch @panic("OOM");

    b.installArtifact(client_exe);

    const run_cmd = b.addRunArtifact(client_exe);

    run_cmd.step.dependOn(b.getInstallStep());

    zcc.createStep(b, "cdb", targets.toOwnedSlice() catch @panic("OOM"));

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
