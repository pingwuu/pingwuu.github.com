---
layout: post
title:  "Markdown Basic Usage"
date:   2019-06-03 09:40:00 +0800
categories: markdown
comments: true
---

# Headers

**Example:** 

```
# This is a H1 header

## This is a H2 header

### This is a H3 header

#### This is a H4 header

##### This is a H5 header
```

**Result:**

# This is a H1 header

## This is a H2 header

### This is a H3 header

#### This is a H4 header

##### This is a H5 header

# Paragraphs and line breaks

Make your text easier to ready by breaking it up with paragraphs or line breaks.

In pull request comments, select **Enter** to insert a line break, and begin text on a new line.

In a Markdown file or widget, enter two spaces before the line break to begin a new paragraph, or enter two consecutive line breaks to begin a new paragraph.

**Example - pull request comment:**

```
Add lines between your text with the Enter key.
This spaces your text better and makes it easier to read.
```

**Result:**

Add lines between your text with the Enter key. This spaces your text better and makes it easier to read.

**Example - Markdown file or widget:**

```
Add two spaces prior to the end of the line.(space, space)  
This adds space in between paragraphs.
```

**Result:**

Add two spaces prior to the end of the line. (space, space)  

This adds space in between paragraphs.

# Block quotes

**Example:**

```
> Single line quote
>> Nexted
>> multiple line
>> quote
```

**Result:**

> Single line quote
>
> > Nested
> >
> > multiple line
> >
> > quote

# Horizontal rules

To add a horizontal rule, add a line that's a series of dashes `---`, The line above the line containing the `---`must be blank.

**Example:**

```
above

----
below
```

**Result**

above

---

below

# Emphasis (bold, italics, strikethrough)

You can emphasize text by applying bold, italics, or strikethrough to characters:

- To apply italics: surround the text with an asterisk `*` or underscore `_`
- To apply bold: surround the text with double asterisk `**` 
- To apply strikethrough: surround the text with double tilde characters `~~` 

**Example:**

```
Use _emphasis_ in comments to express **strong** opinions and point out ~~corrections~~
**_Bold, italicized text_**
**~~Bold, strike-through text~~**
```

**Result**

Use emphasis in comments to express **strong** opinions and point out ~~corrections~~  **_Bold, italicized text_** **~~Bold, strike-through text~~**  

# Code highlighting #



# Tables



# Lists



# Links



# Images



# Checklist or task list



# Emoji



# Ignore or escape Markdown syntax to enter specific or literal characters



# Attachments



# Mathematical notation and characters





# Reference URL

[1. Syntax guidance for basic Markdown usage](https://docs.microsoft.com/en-us/azure/devops/project/wiki/markdown-guidance?view=azure-devops)



---

[jekyll-docs]: https://jekyllrb.com/docs/home
[jekyll-gh]:   https://github.com/jekyll/jekyll
[jekyll-talk]: https://talk.jekyllrb.com/
