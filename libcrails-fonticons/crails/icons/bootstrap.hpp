#pragma once
#include "../icons.hpp"

namespace Crails
{
  namespace Bootstrap
  {
    class IconTheme : public FontIconTheme
    {
      SINGLETON_IMPLEMENTATION(IconTheme, FontIconTheme)
    public:
      IconTheme();

      std::string get(FontIcon::IconIdentity icon, short style = -1) const override;
      std::string stylesheet_cdn_url() const override;
    };
  }
}
