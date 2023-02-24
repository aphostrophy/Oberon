#include "oberon_common_repository.h"

void pipeline_push_command(oberon_ctx *ctx, const char *format, ...)
{
    char buf[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    redisAppendCommand(ctx->redis_context, buf);
    ctx->redis_cmd_cnt += 1;
}

void pipeline_push_command_argv(oberon_ctx *ctx, int argc, const char **argv, const size_t *argvlen)
{
    redisAppendCommandArgv(ctx->redis_context, argc, argv, argvlen);
    ctx->redis_cmd_cnt += 1;
}