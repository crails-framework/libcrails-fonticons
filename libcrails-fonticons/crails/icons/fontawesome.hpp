#pragma once
#include "../icons.hpp"

namespace Crails
{
  namespace FontAwesome
  {
    enum Style
    {
      Regular = 1, Solid, Brands, Thin, Light, Duotone
    };

    class ThemeBase : public FontIconTheme
    {
    protected:
      ThemeBase(Style value) : default_style(value) {}

      virtual std::string style_prefix(short style) const = 0;

      std::string get(FontIcon::IconIdentity icon, short style = -1) const override;

      const Style default_style = Regular;
    };

    class V6 : public ThemeBase
    {
      SINGLETON_IMPLEMENTATION(V6, FontIconTheme)
    public:
      V6(Style default_style = Solid);
      std::string style_prefix(short style) const override;
      std::string stylesheet_cdn_url() const override;
    };

    class V5 : public ThemeBase
    {
      SINGLETON_IMPLEMENTATION(V5, FontIconTheme)
    public:
      V5(Style default_style = Solid);
      std::string style_prefix(short style) const override;
      std::string stylesheet_cdn_url() const override;
    };
  }
}
