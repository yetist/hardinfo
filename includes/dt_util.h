
#ifndef _DT_UTIL_H_
#define _DT_UTIL_H_

#include <stdint.h>

/* some not-quite-complete stuff that can be disabled */
#define DTEX_PHREFS 0

#ifndef DTR_ROOT
#define DTR_ROOT "/proc/device-tree"
#endif

enum {
    DT_TYPE_ERR,

    DT_NODE,
    DTP_UNK,     /* arbitrary-length byte sequence */
    DTP_EMPTY,   /* empty property */
    DTP_STR,     /* null-delimited list of strings */
    DTP_HEX,     /* list of 32-bit values displayed in hex */
    DTP_UINT,
 /* DTP_INT, */
    DTP_PH,      /* phandle */
    DTP_PH_REF,  /* reference to phandle */
};

/* simplest, no aliases.
 * use dtr_get_prop_str() for complete. */
char* dtr_get_string(const char *p);

typedef uint32_t dt_uint; /* big-endian */

typedef struct _dtr dtr;
typedef struct _dtr_obj dtr_obj;

dtr *dtr_new(char *base_path); /* NULL for DTR_ROOT */
void dtr_free(dtr *);
const char *dtr_base_path(dtr *);

dtr_obj *dtr_obj_read(dtr *, const char *dtp);
void dtr_obj_free(dtr_obj *);
int dtr_obj_type(dtr_obj *);
char *dtr_obj_alias(dtr_obj *);
char *dtr_obj_path(dtr_obj *);
char *dtr_obj_full_path(dtr_obj *);

char* dtr_str(dtr *, dtr_obj *obj);
dtr_obj *dtr_get_prop_obj(dtr *, dtr_obj *node, const char *name);
char *dtr_get_prop_str(dtr *, dtr_obj *node, const char *name);
uint32_t dtr_get_prop_u32(dtr *, dtr_obj *node, const char *name);

static int dtr_guess_type(dtr_obj *obj);
char *dtr_elem_phref(dtr *, dt_uint e);
char *dtr_elem_hex(dt_uint e);
char *dtr_elem_byte(uint8_t e);
char *dtr_elem_uint(dt_uint e);
char *dtr_list_byte(uint8_t *bytes, unsigned long count);
char *dtr_list_hex(dt_uint *list, unsigned long count);

#endif