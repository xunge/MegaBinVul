typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct _GimpChannel GimpChannel;
typedef struct _GimpChannelClass GimpChannelClass;

#define GIMP_IS_CHANNEL(channel) (1)
#define GIMP_CHANNEL_GET_CLASS(channel) ((GimpChannelClass *)0)
#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)

struct _GimpChannelClass {
  gboolean (*is_empty)(GimpChannel *channel);
};