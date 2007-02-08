Content Taxonomy:
*****************

This module provides a field type for cck for referencing taxonomy terms.

Note: This module requires the applyng of following patch to the taxonomy.module: 
 -->http://drupal.org/node/56670

The content_taxonomy.module implements all basic field functions. 
The other modules offer different widgets (selects,..)

Settings:
---------
For every field you have to select the vocabulary and optional a parent term in the field settings. 
If a parent is selected, only children of this parent will be given to the form, else the whole vocabulary.
Additional you can choose whether the term is saved as a real tag in the term_node table (standard)
or the term is only saved in a cck-table (so not a real term - node connection) 


content_taxonomy_select:
------------------------
 defines a multiple/single select field. 


content_taxonomy_options:
-------------------------
 provides radios/checkboxes (depends on single/multiple)


content_taxonomy_autocomplete:
------------------------------
 provides autocomplete. synonyms are considered by this autocomplete. Optional you can restrict the
 saving of new terms.


content_taxonomy_activeselect:
------------------------------
 requires the activeselect.module
 offers dependant selects, at the moment 2-3 bars are possible


