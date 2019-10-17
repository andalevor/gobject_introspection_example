#include "girtest_object.h"

/**
 * SECTION: girtest_object
 * @short_description: A gir test class.
 *
 * The #GirtestObject is a class to test gobject introspection.
 */

/**
 * GirtestObject:
 * @name: name to greet #gchar
 *
 * Object with single method which greets @name.
 */
struct _GirtestObject {
  GObject parent_instance;
  gchar *name;
};

/**
 * girtest_object_greet:
 * @self: A #GirtestObject
 *
 * Prints greating for name from #GirtestObject.
 */
void
girtest_object_greet (GirtestObject *self)
{
  g_print ("Hello %s!\n", self->name);
}

G_DEFINE_TYPE (GirtestObject, girtest_object, G_TYPE_OBJECT)

enum
{
  PROP_NAME = 1,
  N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

static void
girtest_object_set_property (GObject *object, guint property_id,
			     const GValue *value, GParamSpec *pspec)
{
  GirtestObject *self = GIRTEST_OBJECT (object);

  switch (property_id)
    {
    case PROP_NAME:
      g_free (self->name);
      self->name = g_value_dup_string (value);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
girtest_object_get_property (GObject *object, guint property_id, GValue *value,
			     GParamSpec *pspec)
{
  GirtestObject *self = GIRTEST_OBJECT (object);

  switch (property_id)
    {
    case PROP_NAME:
      g_value_set_string (value, self->name);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
girtest_object_dispose (GObject *gobject)
{
  G_OBJECT_CLASS (girtest_object_parent_class)->dispose (gobject);
}

static void
girtest_object_finalize (GObject *gobject)
{
  GirtestObject *self = GIRTEST_OBJECT (gobject);
  g_free(self->name);
  G_OBJECT_CLASS (girtest_object_parent_class)->finalize (gobject);
}

static void
girtest_object_class_init (GirtestObjectClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->set_property = girtest_object_set_property;
  object_class->get_property = girtest_object_get_property;
  object_class->dispose = girtest_object_dispose;
  object_class->finalize = girtest_object_finalize;

  /**
   * GirtestObject:name:
   *
   * Name to greet.
   */
  obj_properties[PROP_NAME] =
    g_param_spec_string ("name",
			 "Name",
			 "Name to greet.",
			 "world",
			 G_PARAM_CONSTRUCT | G_PARAM_READWRITE);

  g_object_class_install_properties (object_class, N_PROPERTIES,
				     obj_properties);
}

static void
girtest_object_init (GirtestObject *self)
{
}

GirtestObject *
girtest_object_new (void)
{
  return g_object_new (GIRTEST_TYPE_OBJECT, NULL);
}
