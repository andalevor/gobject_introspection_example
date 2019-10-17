#ifndef __GIRTEST_OBJECT_H__
#define __GIRTEST_OBJECT_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define GIRTEST_TYPE_OBJECT girtest_object_get_type()
G_DECLARE_FINAL_TYPE(GirtestObject, girtest_object, GIRTEST, OBJECT, GObject)

GirtestObject *girtest_object_new(void);
void girtest_object_greet(GirtestObject *self);

G_END_DECLS

#endif /* __TEST_OBJECT_H__ */
