#ifndef art__unicode__encoder_hxx_
#define art__unicode__encoder_hxx_

#include <cstdint>

namespace art::unicode
{

  /// Abstract encoder.
  ///
  class encoder_t
  {
  public:
    virtual
    void
    encode(std::uint32_t) = 0;

  protected:
    /// Constructor.
    ///
    encoder_t();

    /// Copy-construction is prohibited.
    ///
    encoder_t(encoder_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    encoder_t(encoder_t&&) = delete;

    /// Copy-assignment is prohibited.
    ///
    encoder_t&
    operator=(encoder_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    encoder_t&
    operator=(encoder_t&&) = delete;

  };

} // namespace art::unicode

#endif
