
/** To support the widest amount of pre-existing technologies, the
 * Sizr engine will need to support a programming-independent interface,
 * probably some JSON or YAML input scheme
 */

struct Query {};

/** A parser for a language */
struct LanguageBackend {
  virtual ~LanguageBackend();
  AST parse(const Source& src);
  Source serialize(const SourceFormatter& formatter, const AST& ast);
};

struct Asserter {
  LanguageBackend& language;
  Asserter(AST& ast);
  // preempt a query
  void preempt(const Query& assertion);
};

/** language-specific textual format for AST code constructs and nodes */
struct SourceFormatter {
  virtual ~SourceFormatter();

};

/** language-specific defaults for AST code constructs and nodes */
struct SourceNodeDefaults {
  // 
  virtual ~SourceNodeDefaults();
};


struct CppLanguage {
};

struct CppBackend : public LangugageBackend {
};

struct CppNodeDefaults : public SourceNodeDefaults {
  struct {
    bool final = false;
  } Class;
};
