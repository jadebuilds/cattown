"""Sphinx configuration."""
project = "Cat Town"
author = "Feline Entertainment Systems"
copyright = "2024, Feline Entertainment Systems"
extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.napoleon",
    "sphinx_click",
    "myst_parser",
]
autodoc_typehints = "description"
html_theme = "furo"
