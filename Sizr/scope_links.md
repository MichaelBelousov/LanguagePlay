
# Specially Linked Scopes

Some scopes have unique links to additional scopes, to make querying
more natural


Implementation Scope:
- expressions

Argument Scope (`(`, `<`):
- `,` per argument scope
- `{` parent implementation scope
- `.` parent member scope

Per Argument Scope (`,`):
- `,` next per argument scope
- `{` parent implementation scope
- `.` parent member scope


Inheritance Scope (`:`):
- `,` per inheritor scope
- `{` parent implementation scope
- `.` parent member scope

Per Inheritor Scope (`,`):
- `,` next per inheritor scope
- `{` parent implementation scope
- `.` parent member scope
