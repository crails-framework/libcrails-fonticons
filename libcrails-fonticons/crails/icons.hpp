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
      EllipsisVertical, Ellipsis,
      Add, Destroy, Save, Forbid,
      MinusBox, PlusBox, Settings, Tools,
      Refresh, Sync, Search, Magic, Preview,
      Sort, SortAsc, SortDesc,
      Star, HalfStar,
      Edit, ExternalLink,
      Check, Calendar,
      Menu
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
