#include "fontawesome.hpp"

using namespace Crails;
using namespace Crails::FontIcon;
using namespace std;

static const map<IconIdentity, string> default_set = {
  {ArrowLeft,        "arrow-left"},
  {ArrowRight,       "arrow-right"},
  {ArrowUp,          "arrow-up"},
  {ArrowDown,        "arrow-down"},
  {ChevronLeft,      "chevron-left"},
  {ChevronRight,     "chevron-right"},
  {ChevronUp,        "chevron-up"},
  {ChevronDown,      "chevron-down"},
  {Add,              "plus"},
  {Save,             "save"},
  {Destroy,          "trash"},
  {Ellipsis,         "ellipsis"},
  {EllipsisVertical, "ellipsis-vertical"},
  {Forbid,           "ban"},
  {Menu,             "bars"},
  {MinusBox,         "minus-square"},
  {Plugin,           "puzzle-piece"},
  {PlusBox,          "plus-square"},
  {Settings,         "wrench"},
  {Tools,            "tools"},
  {Refresh,          "sync-alt"},
  {Sync,             "sync"},
  {Sort,             "sort"},
  {SortAsc,          "sort-up"},
  {SortDesc,         "sort-down"},
  {Star,             "star"},
  {HalfStar,         "star-half"},
  {Search,           "search"},
  {Magic,            "magic"},
  {Preview,          "eye"},
  {Edit,             "edit"},
  {ExternalLink,     "external-link"},
  {Check,            "check"},
  {Calendar,         "calendar"}
};

string FontAwesome::ThemeBase::get(FontIcon::IconIdentity icon, short style) const
{
  string result = "fa-" + FontIconTheme::get(icon, style);

  if (style < 0)
    style = default_style;
  result = style_prefix(style) + ' ' + result;
  return result;
}

FontAwesome::V6::V6(FontAwesome::Style default_style) : ThemeBase(default_style)
{
  icons = default_set;
}

string FontAwesome::V6::stylesheet_cdn_url() const
{
  return "https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css";
}

string FontAwesome::V6::style_prefix(short style) const
{
  switch (style)
  {
  case Regular: return "fa-regular";
  case Solid: return "fa-solid";
  case Brands: return "fa-brands";
  case Thin: return "fa-thin";
  case Light: return "fa-light";
  case Duotone: return "fa-duotone";
  }
  return "";
}

FontAwesome::V5::V5(FontAwesome::Style default_style) : ThemeBase(default_style)
{
  icons = default_set;
}

string FontAwesome::V5::stylesheet_cdn_url() const
{
  return "https://use.fontawesome.com/releases/v5.3.1/css/all.css";
}

string FontAwesome::V5::style_prefix(short style) const
{
  switch (style)
  {
  case Regular: return "far";
  case Solid: return "fas";
  case Brands: return "fab";
  case Light: return "fal";
  case Duotone: return "fad";
  }
  return "";
}
