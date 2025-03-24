#ifndef art__unicode__writer_hxx_
#define art__unicode__writer_hxx_

#include <cstdint>
#include <string>

namespace art::unicode
{

  /// Abstract writer.
  ///
  class writer_t
  {
  public:
    /// Destructor.
    ///
    virtual
    ~writer_t() noexcept = default;

    /// Write byte.
    ///
    virtual
    void
    write(std::uint8_t) = 0;

  protected:
    /// Constructor.
    ///
    writer_t() = default;

    /// Copy-construction is prohibited.
    ///
    writer_t(writer_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    writer_t(writer_t&&) = delete;

    /// Copy-assignment is prohibited.
    ///
    writer_t&
    operator=(writer_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    writer_t&
    operator=(writer_t&&) = delete;

  };

  /// String writer.
  ///
  class string_writer_t
    : public writer_t
  {
  public:
    /// Constructor.
    ///
    /// \param str Reference to the output string.
    ///
    explicit
    string_writer_t(std::string& str)
      : _str{str}
    {}

    /// Copy-construction is prohibited.
    ///
    string_writer_t(string_writer_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    string_writer_t(string_writer_t&&) = delete;

    void
    write(uint8_t c) override
    {
      _str += static_cast<char>(c);
    }

    /// Copy-assignment is prohibited.
    ///
    string_writer_t&
    operator=(string_writer_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    string_writer_t&
    operator=(string_writer_t&&) = delete;

  private:
    std::string& _str;

  };

} // namespace art::unicode

#endif
