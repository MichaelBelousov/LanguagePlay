"""
Formatting Backend for Python
"""

import ast


class WritingContext:
    """Context during a write command"""
    def __init__(self):
        self.wraps = False


class NodeFormatTable(dict):
    def __init__(self, node_format_src):
        self._src = node_format_src


class Formatter:
    """create a formatter from a NodeFormatTable for formatting files"""
    def __init__( self
                , node_format_table: (dict, (str, lambda node: str))
                ):
        self._table = node_format_table
        self._formatted = ""
        self._context = WritingContext()

    def _visit(self, node):
        """visit an AST node"""
        node_commands = self._table[node.__name__]
        for command in node_commands.commands:
            self._formatted += execCommand(command, self._context)

    def run(self, ast: ast.AST):
        """run the formatter over the given AST"""
        for node in ast:
            code.interact(local=locals())
            self._visit(node)
        return self._formatted

    def __call__(self, ast):
        return self.run(ast)

def format_src(table, src):
    """format python source """
    tree = ast.parse(src)
    Formatter(table).run(tree)
    print(result.dump())
