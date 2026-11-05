#include "bootstrap.hpp"

using namespace Crails;
using namespace Crails::FontIcon;
using namespace std;

static const map<IconIdentity, string> default_set = {
  {ArrowLeft,          "arrow-left"},
  {ArrowRight,         "arrow-right"},
  {ArrowUp,            "arrow-up"},
  {ArrowDown,          "arrow-down"},
  {ChevronLeft,        "chevron-left"},
  {ChevronRight,       "chevron-right"},
  {ChevronUp,          "chevron-up"},
  {ChevronDown,        "chevron-down"},
  {ChevronDoubleLeft,  "chevron-double-left"},
  {ChevronDoubleRight, "chevron-double-right"},
  {ChevronDoubleUp,    "chevron-double-up"},
  {ChevronDoubleDown,  "chevron-double-down"},
  {DeviceDesktop,      "pc-display-horizontal"},
  {DeviceMobile,       "phone"},
  {DeviceTablet,       "tablet"},
  {DeviceLaptop,       "laptop"},
  {Ellipsis,           "three-dots"},
  {EllipsisVertical,   "three-dots-vertical"},
  {Exit,               "door-open"},
  {Add,                "plus"},
  {Save,               "save"},
  {Destroy,            "trash"},
  {Forbid,             "ban"},
  {Layout,             "columns"},
  {Share,              "share"},
  {Upload,             "upload"},
  {Download,           "download"},
  {Menu,               "menu-up"},
  {MinusBox,           "file-minus"},
  {Move,               "arrows-move"},
  {Plugin,             "plugin"},
  {Settings,           "wrench"},
  {Tools,              "tools"},
  {Refresh,            "arrow-clockwise"},
  {Sync,               "arrow-down-up"},
  {Sort,               "sort-down"},
  {SortAsc,            "sort-down"},
  {SortDesc,           "sort-up"},
  {Star,               "star"},
  {HalfStar,           "star-half"},
  {Search,             "search"},
  {Magic,              "magic"},
  {Preview,            "eye"},
  {Language,           "translate"},
  {Edit,               "pencil"},
  {ExternalLink,       "link-45deg"},
  {Check,              "check"},
  {Calendar,           "calendar"},
  {Cloud,              "cloud"},
  {MediaPlay,          "play"},
  {MediaPause,         "pause"},
  {MediaStop,          "stop"},
  {MediaBackward,      "skip-backward"},
  {MediaForward,       "skip-forward"},
  {AudioVolume,        "volume-off"},
  {AudioVolumeUp,      "volume-up"},
  {AudioVolumeDown,    "volume-down"},
  {AudioVolumeMute,    "volume-mute"},
  {File,               "file"},
  {FileAudio,          "file-music"},
  {FileVideo,          "file-play"},
  {FilePicture,        "image"},
  {FileDocument,       "file-text"}
};

Bootstrap::IconTheme::IconTheme()
{
  icons = default_set;
}

string Bootstrap::IconTheme::stylesheet_cdn_url() const
{
  return "https://cdn.jsdelivr.net/npm/bootstrap-icons@1.13.2/font/bootstrap-icons.min.css";
}

string Bootstrap::IconTheme::get(FontIcon::IconIdentity icon, short) const
{
  return "bi bi-" + FontIconTheme::get(icon);
}
