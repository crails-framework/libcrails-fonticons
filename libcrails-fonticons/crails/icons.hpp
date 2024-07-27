#ifndef  CRAILS_FONTICONS_HPP
# define CRAILS_FONTICONS_HPP

# include <crails/utils/singleton.hpp>
# include <map>

namespace Crails
{
  namespace FontIcon
  {
    enum IconIdentity
    {
      ArrowLeft, ArrowRight, ArrowUp, ArrowDown,
      ChevronLeft, ChevronRight, ChevronUp, ChevronDown,
      ChevronDoubleLeft, ChevronDoubleRight, ChevronDoubleUp, ChevronDoubleDown,
      DeviceDesktop, DeviceMobile, DeviceTablet, DeviceLaptop,
      EllipsisVertical, Ellipsis,
      Exit,
      Layout,
      Add, Destroy, Save, Forbid, Share,
      Upload, Download,
      Move,
      Menu, MinusBox, PlusBox, Settings, Tools, Plugin,
      Refresh, Sync, Search, Magic, Preview,
      Sort, SortAsc, SortDesc,
      Star, HalfStar,
      Edit, ExternalLink,
      Check, Calendar, Cloud,
      MediaPlay, MediaPause, MediaStop, MediaBackward, MediaForward,
      AudioVolume, AudioVolumeUp, AudioVolumeDown, AudioVolumeMute,
      File, FileAudio, FileVideo, FilePicture, FileDocument
    };
  }

  class FontIconTheme
  {
    SINGLETON(FontIconTheme)
  public:
    virtual std::string get(FontIcon::IconIdentity icon, short style = -1) const;
    virtual std::string default_icon() const { return ""; }
    std::string         tag(FontIcon::IconIdentity icon, const std::string& name = "i") const { return tag(icon, -1, name); }
    virtual std::string tag(FontIcon::IconIdentity icon, short style, const std::string& name = "i") const;
    virtual std::string stylesheet_cdn_url() const { return ""; }
    std::string         to_json() const;

  protected:
    std::map<FontIcon::IconIdentity, std::string> icons;
  };

  std::string fonticon_tag(FontIcon::IconIdentity);
  std::string fonticon_cdn_header();
}

#endif
