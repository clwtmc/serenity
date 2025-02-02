@echo off

call pink dll

windres -i serenity.rc -o serenity.o

gcc -Os -o serenity.dll -s jni\jvm.lib -shared out_dll.c dll\stub.c serenity.o -Wl,--subsystem,windows