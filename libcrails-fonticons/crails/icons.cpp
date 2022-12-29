#include "icons.hpp"
#include <crails/datatree.hpp>

using namespace std;

namespace Crails
{
  string fonticon_tag(FontIcon::IconIdentity icon)
  {
    const auto* theme = FontIconTheme::singleton::get();

    return theme ? theme->tag(icon) : string();
  }

  string fonticon_cdn_header()
  {
    const auto* theme = FontIconTheme::singleton::get();

    return theme
      ? "<link rel=\"stylesheet\" href=\"" + theme->stylesheet_cdn_url() + "\"/>"
      : string();
  }

  string FontIconTheme::to_json() const
  {
    DataTree data;

    for (const auto& icon : icons)
      data[to_string(icon.first)] = get(icon.first);
    return data.to_json();
  }

  string FontIconTheme::get(FontIcon::IconIdentity icon, short style) const
  {
    auto it = icons.find(icon);

    if (it != icons.end())
      return it->second;
    return default_icon();
  }

  string FontIconTheme::tag(FontIcon::IconIdentity icon, short style, const string& name) const
  {
    return '<' + name + " class=\"" + get(icon, style) + "\"></" + name + '>';
  }
}
