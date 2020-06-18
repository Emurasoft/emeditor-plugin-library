/*
	Copyright (c) 2019 Emurasoft, Inc.
	Licensed under the MIT license. See LICENSE for details.
*/

// EmEditor Plug-In definition file
// v3.08 (6 Jan 2001)   CCustomizeInfo::m_bIgnoreColorPrint, CCustomizeInfo::m_bNoFullPathIfNotActive added.
// v3.12 (16 Jan 2001)  EEID_ALL_PROP added.
//                      CCustomizeInfo::m_abUrlChar is now BYTE, not bool.  =2 means not permitted at end of URL.
// v3.13 (15 Mar 2001)  EEID_NEW_PASTE_PREFIX, EEID_NEW_PASTE_PREFIX_RETURN, EEID_CUSTOMIZE_TRAY,
//                      EEID_INSERT_CR_LF, EEID_MRU_FONT1 added.
//                      CCustomizeInfo::m_bSaveOverwrite, CCustomizeInfo::m_bNoChangeCrLf,
//                      CCustomizeInfo::m_bShowSpace, CCustomizeInfo::m_bWordWrapMark added.
//                      EI_IS_PROPORTIONAL_FONT added.
// v3.14 (23 Apr 2001)  CCustomizeInfo::m_bPrintSeparatingLines, CCustomizeInfo::m_bSameFontPrint,
//                      CCustomizeInfo::m_bHiliteCorresParen added.
//                      EEID_DELETE_RIGHT_WORD, EEID_NEXT_PAREN, EEID_SHIFT_NEXT_PAREN added.
//                      CHECK_FILE_CHANGED_EXCLUSIVE added.
// v3.15 (22 May 2001)  CCustomizeInfo::m_bDetectUTF8, CCustomizeInfo::m_bDetectCharset,
//                      CCustomizeInfo::m_bDetectAll, CCustomizeInfo::m_bDeleteSpaceEnd,
//                      CCustomizeInfo::m_bSaveAsEntity, CCustomizeInfo::m_bShowControl added.
//                      Changed LOAD_FILE_INFO structure.
//                      CHARSET_OEM added.
//                      EEID_CHARSET_OEM, EEID_TRIM_RIGHT added.
//                      CODEPAGE_DETECT_UTF8, CODEPAGE_DETECT_CHARSET, CODEPAGE_DETECT_ALL added.
// v3.16 (21 Jun 2001)  EEID_FILE_RELOAD_DETECT_ALL added.
//                      SMART_COLOR_ constants redefined.
//                      CColorInfo class redefined.
//                      CCustomizeInfo::m_nHiliteTag, m_nHiliteMultiComment removed.
//                      CCustomizeInfo::m_nSpecialSyntax, m_chEscape, m_bPasteAnsi, m_bQuoteType,
//                      m_szScriptBegin, m_szScriptEnd, m_szLineComment1, m_szLineComment2 added.
// v3.17 (25 Jul 2001)  EEID_DELETE_LEFT_WORD, EEID_FILE_NEW_CONFIG,
//                      EEID_NEW_CONFIG_POPUP, EEID_FONT_POPUP added.
//                      CCustomizeInfo::m_bSaveAsNameEntity, m_chIndentBegin, m_bNewTemplate,
//                      m_chIndentEnd, m_chEndOfStatement added.
// v3.18 (29 Aug 2001)  EEID_RELOAD_POPUP, EEID_DELETE_PANES added.
//                      MAX_RECENT_FILE defined.
// v3.19 (1 Oct 2001)   EVENT_CHAR added.
//                      EEID_SHOW_PLUGINS_BAR added.
//                      SIGNATURE_PIB_LIST is superseded by SIGNATURE_PIB_LIST_2.
// v3.20 (21 Nov 2001)  EP_GET_BITMAP, EP_GET_MASK added.
// v3.22 (2 Jan 2002)   EEID_PRINT_PREVIEW, EEID_WINDOW_TOP, EEID_WINDOW_BOTTOM,
//                      EEID_WINDOW_RIGHT, EEID_WINDOW_LEFT, EEID_HOME_TEXT, EEID_SHIFT_HOME_TEXT,
//                      EEID_KEYBOARD_MAP added.
// v3.23 (31 Jan 2002)  EEID_WINDOW_SPLIT_HORZ, EEID_WINDOW_SPLIT_VERT
//                      EEID_CONTEXT_MENU, EEID_DELETE_LEFT_LINE,
//                      EEID_INSERT_GRAVE, EEID_INSERT_ACUTE, EEID_INSERT_CIRCUMFLEX, EEID_INSERT_TILDE,
//                      EEID_INSERT_DIAERESIS, EEID_INSERT_RING_ABOVE, EEID_INSERT_LIGATURE, EEID_INSERT_CEDILLA,
//                      EEID_INSERT_STROKE, EEID_INSERT_INVERTED_QUESTION, EEID_INSERT_INVERTED_EXCLAMATION, 
//                      EEID_INSERT_COPYRIGHT, EEID_INSERT_REGISTERED, EEID_INSERT_TRADEMARK, EEID_INSERT_EURO added.
// v3.24 (10 Feb 2002)  EVENT_FILE_OPENED event added. EEID_WRAP_BY_PAPER added.
// v3.28 ( 1 Oct 2002)  FLAG_FIND_REG_EXP and FLAG_FIND_CLOSE added.
// v3.29 ( 6 Nov 2002)  EEID_SHOW_TOOLS_BAR, EEID_BOOKMARK_TOGGLE, EEID_BOOKMARK_NEXT, EEID_BOOKMARK_PREV,
//                      EEID_BOOKMARK_CLEAR, EEID_CUSTOMIZE_TOOLS, EEID_TOOL1 added.
// v3.31 (17 Dec 2002)  EEID_RETRIEVE_FIND_TEXT, EEID_COPY_FILE_PATH, EEID_COPY_FILE_DIR, EEID_DUPLICATE_LINE,
//                      EEID_LOAD_WORKSPACE, EEID_SAVE_WORKSPACE, EEID_SAVE_WORKSPACE_EXIT_ALL, EEID_SAVE_WORKSPACE_QUIT_ALL,
//                      EEID_LOGICAL_HOME_TEXT, EEID_SHIFT_LOGICAL_HOME_TEXT, EEID_WINDOW_SPLIT_HORZ_FIX, EEID_WINDOW_SPLIT_VERT_FIX,
//                      EEID_SHOW_WINDOWS_BAR added.
//                      CCustomizeInfo::m_bShowScrollOnlyActive, CCustomizeInfo::m_bWrapPagePrint added.
//                      EI_GET_NEXT_BOOKMARK added.
// v3.32 (25 Jan 2003)  CCustomizeInfo::m_nMaxFindHilite added. CColorInfo structure removed.
//
// v4.00 (18 Dec 2003)  EE_SET_SEL_TYPE, EE_GET_STATUSA, EE_GET_STATUSW, EE_INSERT_FILEA, EE_INSERT_FILEW added.
//                      EE_INSERT_STRINGA, EE_INSERT_STRINGW extended to use lParam.
//                      EE_GET_VERSION extended to use wParam.
//                      Editor_GetVersionEx, VERSION_PRO, VERSION_STD added.
//                      EI_GET_HILITE_FIND, EI_SET_HILITE_FIND, EI_GET_APP_VERSIONA, EI_GET_APP_VERSIONW, EI_GET_READ_ONLY, 
//                      EI_IS_WINDOW_COMBINED, EI_WINDOW_COMBINE added.
//                      EEID_SHOW_BAR_TITLE, EEID_LOCK_TOOLBARS, EEID_WINDOW_COMBINE, EEID_WINDOW_ALWAYS_TOP_ON, EEID_WINDOW_ALWAYS_TOP_OFF, EEID_MOVE_LAST_EDIT,
//                      EEID_MACRO_SAVE, EEID_MACRO_SELECT, EEID_MACRO_EDIT, EEID_MACRO_SELECT_THIS, EEID_CUSTOMIZE_MACRO, EEID_BOOKMARK_NEXT_WITHIN, 
//                      EEID_BOOKMARK_PREV_WITHIN, EEID_BOOKMARK_SET, EEID_BOOKMARK_RESET, EEID_SPACE_TO_TAB, EEID_TABIFY, EEID_UNTABIFY, EEID_INDENT,
//                      EEID_UNINDENT, EEID_MACRO_HELP, EEID_MACRO_HELP_WORD, EEID_REPLACE_IN_FILES, EEID_QUIT_ALL, EEID_MACRO_RUN_OPTIONS, EEID_INSERT_CARON,
//                      EEID_VIEW_MARKS, EEID_EDIT_COMMENT, EEID_EDIT_UNCOMMENT, EEID_INCREASE_FONT_SIZE, EEID_DECREASE_FONT_SIZE added.
// v4.01 (27 Dec 2003)  EI_IS_UNDO_COMBINED added.
//                      EEID_FIND_NEXT_UNICODE, EEID_FIND_PREV_UNICODE, EEID_ERASE_UNICODE_HILITE added.
// v4.02 (30 Jan 2004)  EE_FIND_IN_FILES, EE_REPLACE_IN_FILES added.
// v4.03 (25 Feb 2004)  EE_GET_ANCHOR_POS, EE_SET_ANCHOR_POS added.  EE_SET_CARET_POS extended.
// v4.05 (30 Apr 2004)  "cb" field of GET_LINE_INFO was changed to "cch" for clarity.
// v4.10 ( 1 Jan 2005)  EEID_JOIN_LINES, EEID_SPLIT_LINES, EEID_IMPORT_EXPORT, EEID_CAPITALIZE, EEID_WINDOW_MOVE_NEXT, EEID_WINDOW_MOVE_PREV, EEID_CLOSE_ALL_OTHERS added.
//                      FLAG_CAPITALIZE flag added for EE_CONVERT message.
// v4.13 (15 Feb 2005)  EEID_WINDOW_SPLIT_HORZ_TOGGLE, EEID_WINDOW_SPLIT_VERT_TOGGLE added.
// v5.00 (24 Nov 2005)  EE_GET_REDRAW added.
//                      EVENT_CREATE_FRAME, EVENT_CLOSE_FRMAE, EVENT_DOC_SEL_CHANGED, EVENT_DOC_CLOSE events added.
//                      EEID_GROUP_CLOSE_ALL, EEID_GROUP_CLOSE_OTHERS, EEID_GROUP_CLOSE_LEFT, EEID_GROUP_CLOSE_RIGHT, EEID_NEW_GROUP, EEID_NEW_GROUP_MINIMIZE,
//                      EEID_NEW_GROUP_CASCADE, EEID_NEW_GROUP_HORZ, EEID_NEW_GROUP_VERT, EEID_MOVE_PREV_GROUP, EEID_MOVE_NEXT_GROUP,
//                      EEID_SORT_FILE_NAME, EEID_SORT_TYPE, EEID_SORT_MODIFIED, EEID_SORT_ZORDER, EEID_SORT_ASCENDING, EEID_SORT_DESCENDING,
//                      EEID_AUTO_SORT, EEID_RESTORE_POS, 
//                      EEID_CUSTOMIZE_FILE, EEID_CUSTOMIZE_SEARCH, EEID_CUSTOMIZE_HISTORY, EEID_CUSTOMIZE_WINDOW, EEID_CUSTOMIZE_TAB, 
//                      EEID_CUSTOMIZE_STATUS, EEID_CUSTOMIZE_ADVANCED, EEID_WINDOW_COMBINE_ON, EEID_WINDOW_COMBINE_OFF added.
//                      EE_SAVE_FILEA, EE_SAVE_FILEW, EE_GET_MODIFIED, EE_GET_CONFIGA, EE_GET_CONFIGW, EE_SET_CONFIGA, EE_SET_CONFIGW, EE_INFO extended to use HIWORD(wParam) = iDoc.
//                      Editor_DocSaveFileA, Editor_DocSaveFileW, Editor_DocGetModified, Editor_DocGetConfigA, Editor_DocGetConfigW
//                      Editor_DocSetConfigA, Editor_DocSetConfigW, Editor_DocInfo macros added.
//                      EI_GET_DOC_COUNT, EI_INDEX_TO_DOC, EI_DOC_TO_INDEX, EI_ZORDER_TO_DOC, EI_DOC_TO_ZORDER, EI_GET_ACTIVE_INDEX, EI_SET_ACTIVE_INDEX, 
//                      EI_GET_FULL_TITLEA, EI_GET_FULL_TITLEW, EI_GET_SHORT_TITLEA, EI_GET_SHORT_TITLEW, EI_GET_SAVE_AS_TITLEA, EI_GET_SAVE_AS_TITLEW, 
//                      EI_MOVE_ORDER, EI_CLOSE_DOC, EI_SAVE_DOC added for EE_INFO commands.
//                      HEEDOC (handle to document) type defined.
//                      Type changes for x64 (EE_GET_SEL_TEXTA, EE_GET_SEL_TEXTW, EE_GET_LINES, EE_GET_LINEA, EE_GET_LINEW, EE_GET_CARET_POS
//                      EE_DEV_TO_VIEW, EE_GET_PAGE_SIZE, EE_GET_SCROLL_POS, EE_LINE_FROM_CHAR, EE_LINE_INDEX, EE_LOGICAL_TO_SERIAL, EE_LOGICAL_TO_VIEW,
//                      EE_SERIAL_TO_LOGICAL, EE_SET_CARET_POS, EE_SET_SCROLL_POS, EE_VIEW_TO_DEV, EE_VIEW_TO_LOGICAL, EE_GET_SEL_START,
//                      EE_GET_SEL_END, EE_SET_SEL_LENGTH, EE_SET_SEL_VIEW, EE_GET_MARGIN, EE_GET_STATUSA, EE_GET_STATUSW, EE_GET_ANCHOR_POS,
//                      EE_SET_ANCHOR_POS messages, 
//                      GET_LINE_INFO, GREP_INFOW, GREP_INFOA, LOAD_FILE_INFO, LOAD_FILE_INFO_EX structures
//                      EE_DO_IDLE message (Editor_DoIdle) added.
//                      EE_GET_SEL_TYPE, EE_SET_SEL_TYPE, EE_SET_SCROLL_POS expanded to use wParam.
//                      EP_GET_INFO added for plugin message.
// v6.00 (7 Jun 2006)   EEID_ACTIVE_PANE, EEID_OUTLINE_COLLAPSE_ALL, EEID_OUTLINE_EXPAND_ALL, EEID_OUTLINE_TOGGLE_LINE,
//                      EEID_OUTLINE_COLLAPSE_LINE, EEID_OUTLINE_EXPAND_LINE, EEID_OUTLINE_NEXT_NODE, EEID_OUTLINE_PREV_NODE,
//                      EEID_SHIFT_NEXT_NODE, EEID_SHIFT_PREV_NODE, EEID_RESTORE_DELETED, EEID_VIEW_OUTPUT command added.
//                      EE_CUSTOM_BAR_OPEN, EE_CUSTOM_BAR_CLOSE, EE_MATCH_REGEX, EE_FIND_REGEX, EE_GET_OUTLINE_LEVEL, EE_SET_OUTLINE_LEVEL,
//                      EE_SHOW_OUTLINE, EE_ENUM_CONFIG messages added.
//						EVENT_IDLE, EVENT_CUSTOM_BAR_CLOSED, EVENT_CUSTOM_BAR_CLOSING events added.
//                      EP_PRE_TRANSLATE_MSG added for plugin message.
//
// v7.00 (18 Dec 2007)  m_nKanjiRead renamed to m_nEncodingRead, m_nEncodeNew renamed to m_nEncodingNew, m_nEncodeWrite renamed to m_nEncodingWrite
//                      EE_TOOLBAR_OPEN, EE_TOOLBAR_CLOSE, EE_TOOLBAR_SHOW, EE_HELP, EE_REG_SET_VALUE, EE_REG_QUERY_VALUE, EE_QUERY_STRING, 
//                      EE_KEYBOARD_PROP, EE_GET_ACCEL_ARRAY, EE_OUTPUT_STRING, EE_OUTPUT_DIR, EE_ENUM_HIGHLIGHT messages added.
//                      Editor_ToolbarOpen, Editor_ToolbarClose, Editor_ToolbarShow, Editor_Help, Editor_RegSetValue, Editor_RegQueryValue, Editor_QueryString,
//                      Editor_KeyboardProp, Editor_GetAccelArray, Editor_OutputString, Editor_OutputDir, Editor_EnumHighlight inline functions added.
//                      TOOLBAR_INFO, REG_SET_VALUE_INFO, REG_QUERY_VALUE_INFO structures added.
//                      EVENT_TOOLBAR_CLOSED, EVENT_TOOLBAR_SHOW events added.
//                      m_bVirtualSpace member added to CCustomizeInfo.
//                      EI_GET_CURRENT_FOLDER, EI_IS_LARGE_DOC flag added.
//                      EE_GET_LINES, EE_GETLINEW, EE_GETLINEA (GET_LINE_INFO structure) supports iDoc parameter.
//                      Editor_DocGetLines inline functions added.
// v7.00.4 (6 Mar 2008) POS_SCROLL_ALWAYS flag added.
//
// v8.00 (16 Aug 2008)  EI_USE_INI, EI_GET_LANGUAGE flags added.
//						m_bShowIndentGuides, m_bDottedLine members added to CCustomizeInfo.
//                      EE_GET_DROPPED_FILE message added.
//						EP_USE_DROPPED_FILES message to plug-ins added.
//						EVENT_SAVING, EVENT_DROPPED events added.
//
// v9.00 (11 Oct 2009)  EE_CLIP_HISTORY, EE_EDIT_TEMP, EE_GET_ATTR, EE_GET_OUTPUT_STRING, EE_RUN_MACRO messages added.
//                      ATTR_INFO, CLIP_INFO, RUN_MACRO_INFO, TEMP_INFO structures added.
//                      Editor_ActivateTemp, Editor_CloseTemp, Editor_EditTemp, Editor_GetAttr, Editor_GetClip, Editor_GetClipPos, Editor_GetOutputString, Editor_InsertClip, Editor_RunMacro, Editor_SaveTemp, Editor_RemoveClip, Editor_RotateClip inline functions.
//                      EP_DISABLE_AUTO_COMPLETE message to plug-ins added.
//                      EVENT_HISTORY, EVENT_TEMP_SAVING events added.
//                      FIND_REGEX_INFO structure was extended with members for the replace expression.
//						EI_COMBINE_HISTORY, EI_GET_BAR_TEXT_COLOR, EI_GET_BAR_BACK_COLOR, EI_GET_RETURN_TYPE flags added.
//
// v9.01 (14 Oct 2009)  EEID_CHECK_UPDATES, EEID_CUSTOMIZE_UPDATE_CHECKER added.
//
// v10.00 (30 Jun 2010) EE_GET_WORD message added.
//                      Editor_GetWord inline function added.
//                      EI_GET_ACTIVE_DOC, EI_SET_ACTIVE_DOC, EI_GET_SYNC_SESSION, and EI_GET_LOC_DLL_INSTANCE flags added.
//						byteCrLf field and FLAG_GET_CRLF_BYTE flag was added to the GET_LINE_INFO structure.
//                      New commands (from EEID_SAVE_UTF16LE_SIGN through EEID_NUMBERING) added.
// v11.00 (13 Aug 2011) CCustomizeInfo::m_bHighlightCharRef
//                      New commands (from EEID_SHOW_FIND_BAR through EEID_CLOSE_FIND_BAR and EEID_RECENT_CLOSED_FILE1) added.
// v12.00 (30 Aug 2012) EI_GET_RES_DLL_INSTANCE added.
//                      New commands (from EEID_BOOKMARK_INVERT through EEID_SHIFT_NEXT_TAG) added.
// v13.00 ( 7 Jun 2013) EE_GET_MULTI_SEL and EE_SET_OUTLINE_ARRAY messages added.
//                      OUTLINE_ARRAY_INFO structure added.
//                      EI_GET_CMD_LIST_SIZE flag was added to the EE_INFO message.
//                      CCustomizeInfo::m_bPromptRename added.
//                      EVENT_LANGUAGE was renamed to EVENT_UI_CHANGED.
//                      New commands (from EEID_SELECT_ALL_OCCURRENCES through EEID_BOOKMARK_COPY) added.
// v14.00 ( 9 Dec 2013) New commands (from EEID_DECODE_PERCENT through EEID_MOVE_LINE_DOWN) added.
//                      New flags for Find/Replace in Files: FLAG_FIND_OUTPUT_DISPLAY and FLAG_GREP_NO_CLOSE were added.
// v14.1  (18 Dec 2013) SMART_COLOR_BOOKMARK and MAX_SMART_COLOR_V12 added.
//                      MAX_SMART_COLOR changed from 59 to 60.
//                      CCustomizeInfo::m_bInitialFolder, m_szNewLineComment1, m_szNewLineComment2, and m_szInitialFolder were added.
//                      EEID_RESET_ALL was added.
// v14.2  (28 Dec 2013) EEID_INSERT_MACRON, EEID_ADD_REMOVE_GUIDE, and EEID_VIEW_USER_DEFINED_GUIDES were added.
//                      CCustomizeInfo::m_bShowUserDefinedGuides was added.
// v14.4  ( 6 May 2014) EE_GET_COLOR message (Editor_GetColor inline function) was added.
//                      GET_COLOR_INFO structure was added.
//                      EI_GET_DISCARD_UNDO and EI_SET_DISCARD_UNDO commands were added to the EE_INFO message.
//                      LONG_PTR_MIN and LONG_PTR_MAX contants were defined. EE_VIEW_TO_DEV message might return these values.
// v14.5  (18 Jun 2014) EEID_OUTLINE_SYNC_BAR_TO_GUIDE added.
// v14.6  (21 Oct 2014) EI_GET_HEADING_LINES, EI_SET_HEADING_LINES, EI_GET_NARROWING_TOP, EI_SET_NARROWING_TOP, EI_GET_NARROWING_BOTTOM, EI_SET_NARROWING_BOTTOM were added to the EE_INFO message.
//                      FLAG_FIND_SEL_ONLY, FLAG_FIND_EXTRACT, FLAG_FIND_FILTER, FLAG_FIND_UPDATE_MARKER were added.
//                      m_bPreferUtf8, m_byteDetectSV were added to the CCustomizeInfo class.
//                      EEID_HEADING_TOGGLE ... ID_FILTERBAR_LIMIT, EEID_SV_MODE, EEID_CONVERT_TO_SV, EEID_CUSTOMIZE_SV commands were added.
// v14.7                EEID_FILTERBAR_NEGATIVE ... EEID_SORT_LENGTH_D added.
//                      FLAG_FIND_NEGATIVE added.
//                      GET_CELL_INFO structure added.
//                      EE_GET_CELL message and Editor_GetCell inline function added.
//                      EE_FILTER message and Editor_Filter inline fuction and FILTER_INFO structure added.
// v14.8				EE_JOIN message and Editor_Join inline function and JOIN_INFO structure added. 
//						FLAG_FIND_REMOVE_LAST flag added.
//						EEID_DELETE_DUPLICATE_ADVANCED ... EEID_JOIN_CSV added.
// v14.9				EEID_REMOVE_EMBEDDED_NL, EEID_FINDBAR_EMBEDDED_NL added.
// v15.0                The xBegin and xEnd fields and the FLAG_FIND_LOGICAL_OR flag were added to the FILTER_INFO structure. 
//                      The xBegin and xEnd parameters and the FLAG_FIND_LOGICAL_OR flag were added to the Editor_Filter inline function. 
//                      EEID_WORKSPACE_OPEN, EEID_WORKSPACE_SAVE_AS, EEID_WORKSPACE_SAVE_CURRENT, EEID_FILTERBAR_BOOKMARK, EEID_FILTERBAR_EXTRACT, and EEID_WORKSPACE_RECENT_FILE1 commands were added.
// v15.1                EEID_EXTRACT_COLUMNS and EEID_SELECT_COLUMN_WITH_HEADINGS added.
// v15.2				EEID_HELP_INTERNET and EEID_HELP_LOCAL added.
//						EI_GET_CSV flag was added to the EE_INFO message.
// v15.3                EEID_SAVE_CLOSE_DESKTOP through EEID_SAVE_WORKSPACE_QUIT_DESKTOP added.
// v15.4				EI_GET_PRINT_PAGES added.
// v15.8                EI_GET_CELL_MODE and EI_SET_CELL_MODE added.
// v15.9                The FIND_REGEX_INFO_EX structure was extended. The BACK_REF structure was added.
// v16.0                The EE_GET_FILTER message, the Editor_GetFilter inline function, and the FILTER_INFO_EX structure were added.
// v16.1                EEID_SHOW_CELL_BAR, EEID_CELL_BAR_OPTIONS, EEID_CELL_BAR_AUTO_SHOW, EEID_CELL_BAR_AUTO_FOCUS, and EEID_CELL_BAR_AUTO_HEIGHT added.
// v16.3                EI_GET_DPI_OPTIONS and EI_SET_DPI_OPTIONS flags were added to the EE_INFO message.
//                      m_byteMinimapAspectPercent and m_byteMinimapZoomPercent were added to CCustomizeInfo.
//                      SCROLL_FLAG_MINIMAP and SCROLL_FLAG_SHOW_ENTIRE flags were added for the m_byteScrollFlags member of CCustomizeInfo.
//                      EEID_FILTER_OUT_WORD through EEID_MINIMAP_ENTIRE_MAP were added. 
// v16.4                EE_MANAGE_DUPLICATES, EE_SORT messages were added.
//                      Editor_ManageDuplicates and Editor_Sort inline functions were added.
//                      MANAGE_DUPLICATES_INFO, COLUMN_INFO, and SORT_INFO structures were added.
//                      EEID_AUTO_COPY command was added.
// v16.6                EEID_CUSTOMIZE_FORMAT command was added.
// v16.7                EE_SET_CELL, EE_SET_COLUMN messages, Editor_SetCell, Editor_SetColumn inline functions, COLUMN_STRUCT structure were added.
// v16.8                EE_GET_COLUMN messages, and Editor_GetColumn inline functions were added
// v16.9                EE_SHOW_TIP and EE_GET_ACTIVE_STRING messages were added
//                      Editor_ShowTip and Editor_GetActiveString inline functions were added
//                      TIP_INFO and ACTIVE_STRING_INFO structures were added
//                      EEID_FILTER_COLUMN and EEID_CUSTOMIZE_ACTIVE_STRING commands were added
// v17.0                EI_GET_REGISTERED_NAME added.
//                      EEID_DELETE_OLD_SETTINGS added.
// v17.1                EEID_HEADER_TOGGLE, EEID_HEADER_NUM, EEID_HEADER_ALPHA, and EEID_HEADER_ZERO_BASE were added.
// v17.2				EI_VALIDATE_CSV, EI_GET_CLIENT_RECT_NO_BARS were added.
//                      EEID_SCROLL_MARKS_TOGGLE through EEID_MAKE_COLUMNS_SAME commands were added.
// v17.3                EEID_MOVE_COLUMN_RIGHT and EEID_MOVE_COLUMN_LEFT commands were added.
// v17.4				Added FLAG_FIND_BOL, FLAG_FIND_EOL, and FLAG_FIND_LOOKAROUND constants.
// v17.5				Added EE_AUTOFILL message, Editor_AutoFill inline function, AUTOFILL_INFO structure.
// v17.6				MANAGE_DUPLICATES_IGNORE_EMPTY_CELLS, SORT_UNQUOTE_CELLS flags added. 
// v17.7				EE_COMPARE message, Editor_Compare inline function, COMPARE_INFO structure added.
//                      EEID_CUSTOMIZE_RENDERING and EEID_COMPARE_GENERATE_REPORT added.
// v17.8                LFI_USE_TEMP_FILE and LFI_DONT_USE_TEMP_FILE added.
//                      SMART_COLOR_OPEN_FILTER added.
// v18.1				nLimit field added to the GREP_INFO_EX structure.
// v18.4				Added EEID_CLEAR_SAVED_MARKERS, EEID_CUSTOMIZE_OPTIMIZATION, EEID_FILTER_OUT_COLUMN, EEID_FILTERBAR_NUMBER_RANGE, EEID_FINDBAR_NUMBER_RANGE, EEID_SEL_TRIM_LEFT, EEID_SEL_TRIM_RIGHT
// v18.5                Added EEID_RIGHT_EDGE through EEID_BOX_EXTEND_DOWN
// v18.6				Added EEID_REMOVE_EMPTY_LINES through EEID_FILTERBAR_WHOLE_STRING
// v18.7                Added EEID_CLEAR_CONTENTS.
// v18.8                Added FLAG_JAPANESE_YEN and FLAG_KOREAN_WON flags to the EE_CONVERT message and Editor_Convert inline function.
// v18.9                Added EEID_SORT_IPV4_A to EEID_SORT_IPV6_D.
//                      Added the SORT_IPV4 and SORT_IPV6 flags to the SORT_INFO structure and Editor_Sort inline function.
// v19.0                Added SORT_REVERSE, SORT_INSPECT_NOT_SEL_ONLY and MANAGE_DUPLIDATES_INSPECT_SEL_ONLY.
//                      Added EEID_TOGGLE_VALIDATION_BAR, EEID_SORT_REVERSE, EEID_PROPERTY_VALIDATION, EEID_CUSTOMIZE_VALIDATION
// v19.1                Added the EE_GET_UNICODE_NAME message, Editor_GetUnicodeName inline function, and UNICODE_NAME_INFO structure.
//                      Added the EE_NUMBERING message, Editor_Numbering inline function, and NUMBERING_INFO structure.
//                      Added the EI_GET_CHAR_TYPE command to the EE_INFO message.
//                      Added the FLAG_CONVERT_CUSTOM, FLAG_RIGHT_SINGLE_QUOTATION, and FLAG_RIGHT_DOUBLE_QUOTATION flags and szChars parameter to the EE_CONVERT message and Editor_Convert inline function.
// v19.2                Added the EEID_VIEW_ALL_MARKS coommand.
// v19.7                Added the EDIT_COLUMN_INFO structure, EE_EDIT_COLUMN message, Editor_EditColumn inline function
// v19.8                Added the EE_CONVERT_CSV message, Editor_ConvertCsv inline function, CONVERT_CSV_INFO structure.
// v19.9                Added the EE_SPLIT_COLUMN message, Editor_SplitColumn inline function, SPLIT_COLUMN_INFO structure.

#pragma once

#ifdef __cplusplus
#define EE_STRICT    // uses inline functions instead of macros
#endif

#ifndef _ASSERT
#define _ASSERT(expr) ((void)0)
#endif

#define E_DOCUMENT_1_NOT_FOUND				_HRESULT_TYPEDEF_(0xa0000001L)
#define E_DOCUMENT_2_NOT_FOUND				_HRESULT_TYPEDEF_(0xa0000002L)
#define E_COLUMN_1_NOT_FOUND				_HRESULT_TYPEDEF_(0xa0000003L)
#define E_COLUMN_2_NOT_FOUND				_HRESULT_TYPEDEF_(0xa0000004L)
#define E_SELECT_SYNTAX						_HRESULT_TYPEDEF_(0xa0000005L)
#define E_SELECT_DOCUMENT_NOT_FOUND			_HRESULT_TYPEDEF_(0xa0000006L)
#define E_SELECT_COLUMN_NOT_FOUND			_HRESULT_TYPEDEF_(0xa0000007L)
#define E_DIFFERENT_CSV_MODE				_HRESULT_TYPEDEF_(0xa0000008L)
#define E_NOT_MDI							_HRESULT_TYPEDEF_(0xa0000009L)
#define E_WRITE_TEMP_FILE					_HRESULT_TYPEDEF_(0xa000000aL)
#define E_ABORT_NEED_UNDO					_HRESULT_TYPEDEF_(0xa0000010L)
#define E_CANNOT_FIND_PLUGIN				_HRESULT_TYPEDEF_(0xa0000011L)
#define E_NO_SELECTION						_HRESULT_TYPEDEF_(0xa0000012L)
#define E_CELL_INCLUDES_DELIMITER			_HRESULT_TYPEDEF_(0xa0000013L)
#define E_INCONSISTENT_NUM_OF_CELLS			_HRESULT_TYPEDEF_(0xa0000014L)
#define E_DIFF								_HRESULT_TYPEDEF_(0xa0000015L)  // used internally
#define E_SEL_CONTAINS_NEWLINE				_HRESULT_TYPEDEF_(0xa0000016L)  // used internally
#define E_SEL_SAME_LINE						_HRESULT_TYPEDEF_(0xa0000017L)  // used internally
#define E_FILTER_NOT_SUPPORTED				_HRESULT_TYPEDEF_(0xa0000018L)
#define E_SEL_CONTAINS_READONLY				_HRESULT_TYPEDEF_(0xa0000019L)
#define E_EMPTY_MULTI_SEL					_HRESULT_TYPEDEF_(0xa0000020L)
#define E_FAILED_TO_OPEN					_HRESULT_TYPEDEF_(0xa0000021L)
#define E_MULTI_BYTE_TO_WIDE_CHAR			_HRESULT_TYPEDEF_(0xa0000022L)
#define E_WIDE_CHAR_TO_MULTI_BYTE			_HRESULT_TYPEDEF_(0xa0000023L)
#define E_FAILED_TO_MAP_VIEW				_HRESULT_TYPEDEF_(0xa0000024L)
#define E_GREP_LARGER_THAN_2G				_HRESULT_TYPEDEF_(0xa0000025L)
#define E_BACKUP_COPY						_HRESULT_TYPEDEF_(0xa0000026L)
#define E_DISCARD_UNDO						_HRESULT_TYPEDEF_(0xa0000027L)  // used internally
#define E_SEL_TOO_LONG						_HRESULT_TYPEDEF_(0xa0000028L)  // used internally
#define E_UNSUPPORTED_ENCODING				_HRESULT_TYPEDEF_(0xa0000029L)  // used internally

#define S_MATCHED							_HRESULT_TYPEDEF_(0x20000001L)
#define S_MATCHED_IGNORED					_HRESULT_TYPEDEF_(0x20000002L)
#define S_DIFF								_HRESULT_TYPEDEF_(0x20000003L)
#define S_BINARY_FILE						_HRESULT_TYPEDEF_(0x20000004L)
#define S_SKIPPED_IGNORED					_HRESULT_TYPEDEF_(0x20000005L)
#define S_OPEN_DOCUMENTS_ROUNDED			_HRESULT_TYPEDEF_(0x20000006L)  // used internally

#define DEFAULT_DPI		96

#ifndef CLR_NONE
#define CLR_NONE                0xFFFFFFFFL
#endif

#define REV_VERSION_19_6        27
#define REG_VERSION_19_0        26
#define REG_VERSION_18_7        25
#define REG_VERSION_18_6        24
#define REG_VERSION_18_1        23
#define REG_VERSION_18_0        22
#define REG_VERSION_17_0_2		21
#define REG_VERSION_17_0		20
#define REG_VERSION_17_0_B1		19
#define REG_VERSION_16_9		18
#define REG_VERSION_16_3		17
#define REG_VERSION_14_6		16
#define REG_VERSION_14_3        15
#define REG_VERSION_14          14
#define REG_VERSION_13          13
#define REG_VERSION_10          10
#define REG_VERSION_3           3  // v3
#define REG_VERSION             REV_VERSION_19_6

#define UPDATE_TREE_NONE			0
#define UPDATE_OUTLINE				1
#define UPDATE_TREE_SEL				2
#define UPDATE_TREE_LINE_STRING		3
#define UPDATE_TREE_ALL				4
#define INDENT_BRACES				0
#define INDENT_SPACES				1
#define INDENT_CUSTOM				2
#define INDENT_BRACKETS				3
#define INDENT_CUSTOM_BEGIN_END		4
#define INDENT_TABS					5
#define INDENT_BITS_MASK			7

#define WORK_OUTLINE_ALL			1
#define WORK_TREE_SEL				2

#define MAX_HIGHLIGHT_COLOR	(10 + 5)  // SMART_COLOR_COMPARE_CHANGE ... SMART_COLOR_COMPARE_BLANK added

#define RETURN_METHOD_BOTH		0
#define RETURN_METHOD_CR_ONLY	1
#define RETURN_METHOD_LF_ONLY	2

#define WRAP_NONE		0
#define WRAP_BY_CHAR	1
#define WRAP_BY_WINDOW	2
#define WRAP_BY_PAPER	3
#define MAX_WRAP_MODE	4

#define MIN_MARGIN		10
#define MAX_MARGIN		0x7fff  // inclusive

#define MIN_LINE_SPACE		(-2)
#define MAX_LINE_SPACE		30  // inclusive

#define MIN_CHAR_SPACE		0
#define MAX_CHAR_SPACE		30  // inclusive

#define MIN_FIND_HILITE		0
#define MAX_FIND_HILITE     30  // inclusive

#define SPECIAL_SYNTAX_NONE 0
#define SPECIAL_SYNTAX_HTML 1
#define SPECIAL_SYNTAX_HTML_EMBEDDED 2
#define MAX_SPECIAL_SYNTAX	3

#define MAX_FIND_HISTORY 64
#define DEF_FIND_HISTORY 32
#define MIN_FIND_HISTORY 1
#define MIN_RECENT_FILE 0
#define MAX_RECENT_FILE 64
#define MIN_RECENT_POPUP 1
#define MAX_RECENT_POPUP MAX_RECENT_FILE
#define DEF_RECENT_FILE 16
#define DEF_RECENT_POPUP	8
#define MAX_RECENT_UNDO 64
#define DEF_RECENT_UNDO 8

#define DEFAULT_COLOR		(ULONG_MAX-1)
#define TRANSPARENT_COLOR	(ULONG_MAX-2)
#define NOT_USED_COLOR		TRANSPARENT_COLOR

#define SIGNATURE_FACE_LIST         0x00FF0000
#define SIGNATURE_HILITE_LIST       0x00FF0100
#define SIGNATURE_FIND_LIST         0x00FF0200
#define SIGNATURE_PIK_LIST          0x00FF0300
#define SIGNATURE_PIB_LIST_2        0x00FF0401
#define SIGNATURE_ASSOCIATE_LIST    0x00FF0500
#define SIGNATURE_NEW_ASSOCIATE_LIST   0x00FF0501
#define SIGNATURE_CODEPAGE_LIST_2   0x00FF0601
#define SIGNATURE_MENU_LIST         0x00FF0700
#define SIGNATURE_MENU_LIST_2       0x00FF0701
#define SIGNATURE_TOOL_LIST         0x00FF0800
#define SIGNATURE_TOOL_LIST_2       0x00FF0801
#define SIGNATURE_TOOL_LIST_3       0x00FF0802
#define SIGNATURE_PIK_T_LIST        0x00FF0900
#define SIGNATURE_WORKSPACE_LISTW   0x00FF0A00
#define SIGNATURE_WORKSPACE_LISTA   0x00FF0A01
#define SIGNATURE_WORKSPACE_LISTW_2 0x00FF0A02
#define SIGNATURE_WORKSPACE_LISTA_2 0x00FF0A03
#define SIGNATURE_WORKSPACE_LISTW_3 0x00FF0A06
#define SIGNATURE_WORKSPACE_LISTA_3 0x00FF0A07
#define SIGNATURE_WORKSPACE_LISTW_4 0x00FF0A08 // new v9
#define SIGNATURE_WORKSPACE_LISTW_5 0x00FF0A09 // new v10
#define SIGNATURE_WORKSPACE_LISTW_6 0x00FF0A0A // new v13
#define SIGNATURE_WORKSPACE_LISTW_7 0x00FF0A0B // new v14.4
#define SIGNATURE_WORKSPACE_LISTW_8 0x00FF0A0C // new v15.5
#define SIGNATURE_WORKSPACE_LISTW_9 0x00FF0A0D // new v16.0
/// if you need to add SIGNATURE_WORKSPACE_LISTW_x, remember to edit MyCmdLine.cpp ("wst.") !!
#define SIGNATURE_WORKSPACE_LIST	SIGNATURE_WORKSPACE_LISTW_9
#define SIGNATURE_PIK_M_LIST        0x00FF0B00
#define SIGNATURE_MACRO_LANG_LIST   0x00FF0C00
#define SIGNATURE_THEME_LIST        0x00FF0D00
#define SIGNATURE_PAIR_LIST         0x00FF0E00
#define SIGNATURE_PAIR_LIST_2       0x00FF0E01
#define SIGNATURE_PAIR_LIST_3       0x00FF0E02
#define SIGNATURE_MARKER_LIST       0x00FF0F00
#define SIGNATURE_MARKER_LIST_2     0x00FF0F01
#define SIGNATURE_GUIDE_LIST		0x00ff1000
#define SIGNATURE_SV_LIST			0x00FF1100
#define SIGNATURE_SV_LIST_2			0x00FF1101
#define SIGNATURE_FILTER_LIST		0x00ff1200
#define SIGNATURE_FILTER_LIST_2		0x00ff1201
#define SIGNATURE_COLOR_VAR_LIST	0x00ff1300
#define SIGNATURE_COLOR_VAR_LIST_2	0x00ff1301

#define MAX_CODEPAGE_NAME 80

#define CHARSET_DEFAULT             0
#define CHARSET_ARABIC              1
#define CHARSET_BALTIC              2
#define CHARSET_CENTRAL_EUROPE      3
#define CHARSET_CHINESE_SIMPLIFIED  4
#define CHARSET_CHINESE_TRADITIONAL 5
#define CHARSET_CYRILLIC            6
#define CHARSET_GREEK               7
#define CHARSET_HEBREW              8
#define CHARSET_JAPANESE            9
#define CHARSET_KOREAN              10
#define CHARSET_THAI                11
#define CHARSET_TURKISH             12
#define CHARSET_VIETNAMESE          13
#define CHARSET_WESTERN_EUROPE      14
#define CHARSET_OEM                 15
#define CHARSET_RESERVED_4          16
#define CHARSET_RESERVED_3          17
#define CHARSET_RESERVED_2          18
#define CHARSET_RESERVED_1          19
#define MAX_CHARSET                 20
#define MAX_USED_CHARSET            16

#define CODEPAGE_ANSI               65536
#define CODEPAGE_UNICODE            65537
#define CODEPAGE_UTF16LE            CODEPAGE_UNICODE
#define CODEPAGE_UNICODE_BIGENDIAN  65538
#define CODEPAGE_UTF16BE            CODEPAGE_UNICODE_BIGENDIAN
#define CODEPAGE_BINARY				65539  // v8
#define CODEPAGE_HEX				65540  // v8

#define CODEPAGE_UTF8               65001
#define CODEPAGE_UTF7               65000

#define CODEPAGE_ANSI_FIRST         4
#define CODEPAGE_ANSI_LAST          64999

#define CODEPAGE_932                932     // Japanese Shift-JIS
#define CODEPAGE_JIS                65616   // obsolete, Japanese JIS, use 50220 instead
#define CODEPAGE_EUC                65617   // obsolete, Japanese EUC, use 51932 instead.

#define CODEPAGE_DETECT_UNICODE     0x00020000
#define CODEPAGE_DETECT_UTF8        0x00040000  // v3.15
#define CODEPAGE_DETECT_CHARSET     0x00080000  // v3.15
#define CODEPAGE_DETECT_ALL         0x00100000  // v3.15
#define CODEPAGE_DETECT_FLAGS		(CODEPAGE_DETECT_UNICODE | CODEPAGE_DETECT_UTF8 | CODEPAGE_DETECT_CHARSET | CODEPAGE_DETECT_ALL)
#define CODEPAGE_MASK               0x0001ffff

#define CODEPAGE_AUTO_SJIS_JIS      66049  // obsolete
#define CODEPAGE_AUTO_SJIS_JIS_EUC  66050  // obsolete, use 50932 instead.

#define CODEPAGE_UNKNOWN            66304  // internal use only
#define CODEPAGE_MAYBE_EUC          66305  // internal use only
#define CODEPAGE_CONFIG             66307  // internal use only
#define CODEPAGE_SAME_AS_DOC		66308  // internal use only
#define CODEPAGE_MORE				66309  // internal use only

#ifdef _WIN64
#define MAX_UNDO_COUNT			0x08000000
#else
#define MAX_UNDO_COUNT			0x00100000  // 0x00800000
#endif
#define MIN_UNDO_COUNT			0x100

#define MAX_PLUG_IN_NAME        MAX_PATH
#define MAX_FILE_FILTER_LENGTH    256
#define MAX_FILTER_BUF			10001  // including NULL character
#define MAX_CONFIG_NAME         260
#define MAX_DEF_CONFIG_NAME		32
#define MAX_ASSOCIATE_LENGTH    16
#define MAX_THEME_NAME			32

#define MAX_HEADER              116  // was 128 before v3.16
#define MAX_FOOTER              116  // was 128 before v3.16
#define MAX_KINSOKU_BEGIN       128
#define MAX_KINSOKU_END         128
#define MAX_MULTI_COMMENT_BEGIN 16
#define MAX_MULTI_COMMENT_END   16
#define MAX_LINE_COMMENT        4  // v3.16
#define MAX_NEW_LINE_COMMENT    16 // v14.1
#define MAX_SCRIPT_BEGIN        8  // v3.16
#define MAX_SCRIPT_END          8  // v3.16
#define MAX_PREFIX_LENGTH       80
#define MAX_FILE_FILTER         128
#define MAX_DEF_EXT             128
#define MAX_PREFIX_LIST         40

#define SMART_COLOR_NONE			((BYTE)(-1))
#define SMART_COLOR_NORMAL			0
#define SMART_COLOR_SEL				1
#define SMART_COLOR_CURLINE			2
#define SMART_COLOR_QUOTE			3
#define SMART_COLOR_FIND			4
#define SMART_COLOR_LINK_URL		5
#define SMART_COLOR_LINK_ID			6
#define SMART_COLOR_LINK_TAG		7
#define SMART_COLOR_SINGLE_QUOTES   8
#define SMART_COLOR_DOUBLE_QUOTES   9
#define SMART_COLOR_COMMENT			10
#define SMART_COLOR_SCRIPT			11
#define SMART_COLOR_BRACES			12
#define SMART_COLOR_IN_TAG			13
#define SMART_COLOR_HILITE_1		14
#define SMART_COLOR_HILITE_2		15
#define SMART_COLOR_HILITE_3		16
#define SMART_COLOR_HILITE_4		17
#define SMART_COLOR_HILITE_5		18
#define SMART_COLOR_HILITE_6		19
#define SMART_COLOR_HILITE_7		20
#define SMART_COLOR_HILITE_8		21
#define SMART_COLOR_HILITE_9		22
#define SMART_COLOR_HILITE_10		23
#define SMART_COLOR_RETURN			24
#define SMART_COLOR_LINE			25
#define SMART_COLOR_PAGE_LINE		26
#define SMART_COLOR_LINE_NUMBER		27
#define SMART_COLOR_RULER			28
#define SMART_COLOR_OUTSIDE			29
#define SMART_COLOR_COMPARE_CHANGE	30
#define SMART_COLOR_COMPARE_CHAR	31
#define SMART_COLOR_COMPARE_ADDED	32
#define SMART_COLOR_COMPARE_DELETED	33
#define SMART_COLOR_COMPARE_BLANK	34
#define SMART_COLOR_SPELL			35
#define SMART_COLOR_UNICODE			36
#define SMART_COLOR_VERTICAL_SEL	37
#define SMART_COLOR_HEX_SEL			38
#define SMART_COLOR_INDENT_GUIDES	39
#define SMART_COLOR_HORZ_GRID		40
#define SMART_COLOR_OUTLINE			41
#define SMART_COLOR_LINE_NUMBER_LINES	42
#define SMART_COLOR_RULER_LINES			43
#define SMART_COLOR_VERTICAL_SEPARATOR	44
#define SMART_COLOR_HTML_CHAR_REF	45
#define SMART_COLOR_UCN				46
#define SMART_COLOR_AUTO_MARKER		47
#define SMART_COLOR_MARKER_1		48
#define SMART_COLOR_MARKER_2		49
#define SMART_COLOR_MARKER_3		50
#define SMART_COLOR_MARKER_4		51
#define SMART_COLOR_MARKER_5		52
#define SMART_COLOR_MARKER_6		53
#define SMART_COLOR_MARKER_7		54
#define SMART_COLOR_MARKER_8		55
#define SMART_COLOR_MARKER_9		56
#define SMART_COLOR_MARKER_10		57
#define SMART_COLOR_MATCHING_TAG	58
#define SMART_COLOR_BOOKMARK		59
#define SMART_COLOR_USER_DEFINED_GUIDES	60
#define SMART_COLOR_INDICATOR_MODIFIED	61
#define SMART_COLOR_INDICATOR_SAVED		62
#define SMART_COLOR_INDICATOR_BOOKMARK	63
#define SMART_COLOR_MARKER_MODIFIED	64
#define SMART_COLOR_MARKER_SAVED	65
#define SMART_COLOR_MARKER_BOOKMARK	66
#define SMART_COLOR_MARKER_FOUND	67
#define SMART_COLOR_MARKER_CURSOR	68
#define SMART_COLOR_MARKER_COMPARE_CHANGE	69
#define SMART_COLOR_MARKER_COMPARE_ADDED	70
#define SMART_COLOR_MARKER_COMPARE_DELETED	71
#define SMART_COLOR_HEADINGS		72
#define SMART_COLOR_SEARCH_SEL		73
#define SMART_COLOR_FILTER			74
#define SMART_COLOR_LINK_URL_VISITED	75
#define SMART_COLOR_LINK_ID_VISITED		76
#define SMART_COLOR_LINK_TAG_VISITED	77
#define SMART_COLOR_CELL_TEXT			78
#define SMART_COLOR_CELL_BORDER			79
#define SMART_COLOR_FILTER_SEPARATOR	80
#define SMART_COLOR_MINIMAP_BACKGROUND	81
#define SMART_COLOR_MINIMAP_VIEW		82
#define SMART_COLOR_LINK_IPV4			83
#define SMART_COLOR_LINK_IPV4_VISITED	84
#define SMART_COLOR_LINK_IPV6			85
#define SMART_COLOR_LINK_IPV6_VISITED	86
#define SMART_COLOR_HEX_COLOR			87
#define SMART_COLOR_RGB_COLOR			88
#define SMART_COLOR_LINE_NUMBER_HOVERED	89
#define SMART_COLOR_RULER_HOVERED		90
#define SMART_COLOR_LINE_NUMBER_SEL		91
#define SMART_COLOR_RULER_SEL			92
#define SMART_COLOR_LINE_NUMBER_CURR	93
#define SMART_COLOR_RULER_CURR			94
#define SMART_COLOR_OPEN_FILTER			95  // v17.8
#define SMART_COLOR_MULTI_SELECTION		96  // v18.6
#define SMART_COLOR_VALIDATOR_ERROR		97  // v19.0
#define SMART_COLOR_VALIDATOR_WARNING	98  // v19.0
#define SMART_COLOR_VALIDATOR_MESSAGE	99  // v19.0

#define MAX_SMART_COLOR					100  // 96

#define SMART_COLOR_INVALID				MAX_SMART_COLOR

#define MAX_SMART_COLOR_V15_8		80
#define MAX_SMART_COLOR_V15_4		78
#define MAX_SMART_COLOR_V14_6		75
#define MAX_SMART_COLOR_V14_3		72
#define MAX_SMART_COLOR_V14_2		61
#define MAX_SMART_COLOR_V14			60
#define MAX_SMART_COLOR_V12			59
#define MAX_SMART_COLOR_V11			58
#define MAX_SMART_COLOR_V10			44
#define MAX_SMART_COLOR_V9			30
#define MAX_SMART_COLOR_FIND		(MAX_SMART_COLOR + (MAX_FIND_HILITE + 1))

#define	MAX_MARKER_COLOR			10

#define SMART_COLOR_FONT_NORMAL     0
#define SMART_COLOR_FONT_UNDERLINE  1
#define SMART_COLOR_FONT_BOLD       2
#define SMART_COLOR_FONT_ITALIC     3
#define SMART_COLOR_FONT_WIGGLY		4
#define SMART_COLOR_FONT_DOTTED		5
#define SMART_COLOR_FONT_THICK_LINE	6
#define SMART_COLOR_FONT_NOT_USED   SMART_COLOR_FONT_NORMAL

#define QUOTE_NONE              0
#define QUOTE_SINGLE            1
#define QUOTE_DOUBLE            2
#define QUOTE_BOTH              3
#define QUOTE_CONTINUE          4

// v6
#define CUSTOM_BAR_LEFT		0
#define CUSTOM_BAR_TOP		1
#define CUSTOM_BAR_RIGHT	2
#define CUSTOM_BAR_BOTTOM	3
#define MAX_CUSTOM_BAR		4

// v7
#define EEREG_COMMON				(0x7fffff00)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Common             or eeCommon.ini\[Common]
#define EEREG_REGIST				(0x7fffff01)  // HKEY_CURRENT_USER\Software\EmSoft\Regist                         or eeCommon.ini\[Regist]
#define EEREG_MACROS				(0x7fffff02)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Macros             or eeCommon.ini\[Macros]
#define EEREG_PLUGINS				(0x7fffff03)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\PlugIns            or eeCommon.ini\[PlugIns]
#define EEREG_RECENT_FILE_LIST		(0x7fffff04)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Recent File List   or eeCommon.ini\[Recent File List]
#define EEREG_RECENT_FOLDER_LIST	(0x7fffff05)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Recent Folder List or eeCommon.ini\[Recent Folder List]
#define EEREG_RECENT_FONT_LIST		(0x7fffff06)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Recent Font List   or eeCommon.ini\[Recent Font List]
#define EEREG_RECENT_INSERT_LIST	(0x7fffff07)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Recent Insert List or eeCommon.ini\[Recent Insert List]
//#define EEREG_AUTOSAVE				(0x7fffff08)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\AutoSave           or eeCommon.ini\[AutoSave]
#define EEREG_LM_COMMON				(0x7fffff11)  // HKEY_LOCAL_MACHINE\SOFTWARE\EmSoft\EmEditor v3\Common            or eeLM.ini\[Common]
#define EEREG_LM_REGIST				(0x7fffff12)  // HKEY_LOCAL_MACHINE\SOFTWARE\EmSoft\Regist                        or eeLM.ini\[Regist]
#define EEREG_CONFIG				(0x7fffff20)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditor v3\Config\(pszConfig) or eeConfig.ini\[(pszConfig)]
#define EEREG_EMEDITORPLUGIN		(0x7fffff30)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditorPlugIns                or eePlugins.ini\[(pszConfig)]
#define EEREG_EMEDITORUSERS			(0x7fffff31)  // HKEY_CURRENT_USER\Software\EmSoft\EmEditorUsers				  or eeUsers.ini\[(pszConfig)]
#define IS_EEREG_COMMON(x)			((DWORD)x >= EEREG_COMMON && (DWORD)x < EEREG_LM_COMMON)
#define IS_EEREG_LM(x)				((DWORD)x >= EEREG_LM_COMMON && (DWORD)x < EEREG_CONFIG)
#define	EE_REG_VARIABLE_SIZE		1

// events
#define EVENT_SEL_CHANGED       0x00000010
#define EVENT_CARET_MOVED       0x00000020
#define EVENT_MODIFIED          0x00000040
#define EVENT_SCROLL            0x00000080
#define EVENT_CONFIG_CHANGED    0x00000100
#define EVENT_CHANGE            0x00000200
#define EVENT_CREATE            0x00000400
#define EVENT_CLOSE             0x00000800
#define EVENT_KILL_FOCUS        0x00001000
#define EVENT_SET_FOCUS         0x00002000
#define EVENT_CHAR              0x00004000
#define EVENT_FILE_OPENED       0x00008000

// new events for v5
#define EVENT_CREATE_FRAME      0x00010000
#define EVENT_CLOSE_FRAME       0x00020000
#define EVENT_DOC_SEL_CHANGED   0x00040000
#define EVENT_TAB_MOVED         0x00080000
#define EVENT_DOC_CLOSE			0x00100000

// new events for v6
#define EVENT_IDLE				0x00200000
#define EVENT_CUSTOM_BAR_CLOSED	0x00400000
#define EVENT_CUSTOM_BAR_CLOSING 0x00800000

// new events for v7
#define EVENT_TOOLBAR_CLOSED	0x01000000
#define EVENT_TOOLBAR_SHOW		0x02000000

// new events for v8
#define EVENT_SAVING			0x04000000
#define EVENT_DROPPED			0x08000000
#define EVENT_UI_CHANGED		0x10000000  // was EVENT_LANGUAGE before v13

// flags for EVENT_UI_CHANGED
#define UI_CHANGED_LANGUAGE		0x00000001
#define UI_CHANGED_TOOLBARS		0x00000002
#define UI_CHANGED_DPI			0x00000003

// new events for v9
#define EVENT_HISTORY			0x20000000
#define EVENT_TEMP_SAVING		0x40000000

#define CHAR_NULL 0
#define CHAR_SPACE 1
#define CHAR_MARK 2
#define CHAR_ALPHANUMERIC 3
#define CHAR_KANA		4
#define CHAR_KANA_MARK  5
#define CHAR_DB_SPACE 6
#define CHAR_DB_MARK 7
#define CHAR_DB_ALPHANUMERIC 8
#define CHAR_DB_HIRA 9
#define CHAR_DB_KATA 10
#define CHAR_DB_KANJI 11
#define CHAR_DB_KANA_MARK 12
#define CHAR_SECOND_DB 13
#define CHAR_HANGUL		14
#define CHAR_DB_HANGUL	15

typedef void *HEEDOC;

// EE_LOAD_FILE
typedef struct _LOAD_FILE_INFO {
    size_t cbSize;          // sizeof( LOAD_FILE_INFO )
    UINT nCP;
    BOOL bDetectUnicode;
    BOOL bDetectAll;
    BOOL bDetectCharset;
    BOOL bDetectUTF8;
} LOAD_FILE_INFO;

// EE_LOAD_FILE_EX
typedef struct _LOAD_FILE_INFO_EX {
    size_t cbSize;          // sizeof( LOAD_FILE_INFO_EX )
    UINT nCP;
    BOOL bDetectUnicode;
    BOOL bDetectAll;
    BOOL bDetectCharset;
    BOOL bDetectUTF8;
    UINT nFlags;
} LOAD_FILE_INFO_EX;

// EE_LOAD_FILE_EX_V2
typedef struct _LOAD_FILE_INFO_EX_V2 {
	size_t cbSize;          // sizeof( LOAD_FILE_INFO_EX_V2 )
	UINT nCP;
	BOOL bDetectUnicode;
	BOOL bDetectAll;
	BOOL bDetectCharset;
	BOOL bDetectUTF8;
	UINT nFlags;
	INT_PTR xCursor;
	INT_PTR yCursor;
} LOAD_FILE_INFO_EX_V2;

#define LFI_ALLOW_NEW_WINDOW		1
#define LFI_ALLOW_ASYNC_OPEN		2
#define LFI_USE_TEMP_FILE			4
#define LFI_DONT_USE_TEMP_FILE		8

#define FLAG_CR_AND_LF			0
#define FLAG_CR_ONLY			1
#define FLAG_LF_ONLY			2
#define FLAG_NEWLINE_MIXED		0xff
#define FLAG_ABORT				0xfe

typedef struct _GET_LINE_INFO {
    UINT_PTR	cch;		// in
    UINT		flags;		// in
    UINT_PTR	yLine;		// in
	BYTE		byteCrLf;	// out (valid only when flags contains FLAG_GET_CRLF_BYTE)
} GET_LINE_INFO;

typedef struct _GREP_INFOW {
    size_t  cbSize;         // sizeof( GREP_INFOW )
    UINT    nCP;
    UINT    nFlags;
    LPCWSTR pszFind;
    LPCWSTR pszReplace;
    LPCWSTR pszPath;
    LPCWSTR pszBackupPath;
    LPCWSTR pszFilesToIgnore;
} GREP_INFOW;

typedef struct _GREP_INFO_EX_OLD {
	size_t  cbSize;         // sizeof( GREP_INFO_EX )
	UINT    nCP;
	UINT64  nFlags;
	LPCWSTR pszFind;
	LPCWSTR pszReplace;
	LPCWSTR pszPath;
	LPCWSTR pszBackupPath;
	LPCWSTR pszFilesToIgnore;
} GREP_INFO_EX_OLD;

typedef struct _GREP_INFO_EX {
	size_t  cbSize;         // sizeof( GREP_INFO_EX )
	UINT    nCP;
	UINT64  nFlags;
	LPCWSTR pszFind;
	LPCWSTR pszReplace;
	LPCWSTR pszPath;
	LPCWSTR pszBackupPath;
	LPCWSTR pszFilesToIgnore;
	UINT	nLimit;   // new v18.1
} GREP_INFO_EX;

typedef struct _GREP_INFOA {
    size_t  cbSize;         // sizeof( GREP_INFOA )
    UINT    nCP;
    UINT    nFlags;
    LPCSTR  pszFind;
    LPCSTR  pszReplace;
    LPCSTR  pszPath;
    LPCSTR  pszBackupPath;
    LPCSTR  pszFilesToIgnore;
} GREP_INFOA;

typedef struct _MATCH_REGEX_INFO {
	size_t  cbSize;         // sizeof( MATCH_REGEX_INFO )
	UINT	nFlags;
	LPCWSTR pszRegex;
	LPCWSTR pszText;
	LPCWSTR pszReplace;   // new v9
	LPWSTR  pszResult;  // new v9
	UINT	cchResult;    // new v9
} MATCH_REGEX_INFO;

typedef struct _MATCH_REGEX_INFO_EX {
	size_t  cbSize;         // sizeof( MATCH_REGEX_INFO_EX )
	UINT64	nFlags;
	LPCWSTR pszRegex;
	LPCWSTR pszText;
	LPCWSTR pszReplace;
	LPWSTR  pszResult;
	UINT	cchResult;
} MATCH_REGEX_INFO_EX;

typedef struct _FIND_REGEX_INFO {
	size_t  cbSize;         // sizeof( FIND_REGEX_INFO )
	UINT	nFlags;
	LPCWSTR pszRegex;
	LPCWSTR pszText;
	LPCWSTR* ppszStart;
	LPCWSTR* ppszEnd;
	LPCWSTR* ppszNext;
	LPCWSTR pszReplace;   // new v9
	LPWSTR  pszResult;  // new v9
	UINT	cchResult;    // new v9
} FIND_REGEX_INFO;

typedef struct _FIND_REGEX_INFO_EX_OLD {
	size_t  cbSize;         // sizeof( FIND_REGEX_INFO_EX )
	UINT64	nFlags;
	LPCWSTR pszRegex;
	LPCWSTR pszText;
	LPCWSTR* ppszStart;
	LPCWSTR* ppszEnd;
	LPCWSTR* ppszNext;
	LPCWSTR pszReplace;
	LPWSTR  pszResult;
	UINT	cchResult;
} FIND_REGEX_INFO_EX_OLD;

#define MAX_BACK_REF	1001

typedef struct _BACK_REF {
	UINT	cchBegin;
	UINT	cchEnd;
} BACK_REF;

typedef struct _FIND_REGEX_INFO_EX {
	size_t  cbSize;         // sizeof( FIND_REGEX_INFO_EX )
	UINT64	nFlags;
	LPCWSTR pszRegex;
	LPCWSTR pszText;
	LPCWSTR* ppszStart;
	LPCWSTR* ppszEnd;
	LPCWSTR* ppszNext;
	LPCWSTR pszReplace;
	LPWSTR  pszResult;
	UINT	cchResult;
	LPCWSTR pszStartAt;       // [in] position where you want to start search (equivalent to Onigmo onig_search() start parameter)
	UINT	nBackRefResult;  // [out]
	UINT	nBackRefBuf;     // [in] usually MAX_BACK_REF, or 0 if you don't want back reference results
	BACK_REF BackRef[MAX_BACK_REF];  // BackRef[0] : \0, BackRef[1] : \1, BackRef[2] : \2, ... BackRef[1000] : \k<1000>
} FIND_REGEX_INFO_EX;

typedef struct _CUSTOM_BAR_INFO {
	size_t  cbSize;
	HWND	hwndCustomBar;
	HWND	hwndClient;
	LPCTSTR pszTitle;
	int		iPos;
} CUSTOM_BAR_INFO;

#define CLOSED_FRAME_WINDOW			1
#define CLOSED_ANOTHER_CUSTOM_BAR	2

typedef struct _CUSTOM_BAR_CLOSE_INFO {
	UINT	nID;
	int		iPos;
	DWORD	dwFlags;
} CUSTOM_BAR_CLOSE_INFO;

#if (defined(_WIN64) || defined(_W64))
typedef struct tagPOINT_PTR
{
    LONG_PTR  x;
    LONG_PTR  y;
} POINT_PTR, *PPOINT_PTR;

typedef struct tagSIZE_PTR
{
    LONG_PTR  cx;
    LONG_PTR  cy;
} SIZE_PTR, *PSIZE_PTR;

//#define LONG_PTR_MIN		LLONG_MIN
//#define LONG_PTR_MAX		LLONG_MAX
#else
typedef struct tagPOINT_PTR
{
    LONG  x;
    LONG  y;
} POINT_PTR, *PPOINT_PTR;

typedef struct tagSIZE_PTR
{
    LONG  cx;
    LONG  cy;
} SIZE_PTR, *PSIZE_PTR;

#define LONG_PTR_MIN		LONG_MIN
#define LONG_PTR_MAX		LONG_MAX
#endif

typedef struct tagPOINT64
{
    INT64  x;
    INT64  y;
} POINT64, *PPOINT64;


class CPointPtr : public tagPOINT_PTR
{
public:
// Constructors
	CPointPtr();
	CPointPtr(int initX, int initY);
	CPointPtr(POINT initPt);
	CPointPtr(SIZE initSize);

// Operations
	void Offset(int xOffset, int yOffset);
	void Offset(POINT point);
	void Offset(SIZE size);
	BOOL operator ==(POINT point) const;
	BOOL operator !=(POINT point) const;
	void operator +=(SIZE size);
	void operator -=(SIZE size);
	void operator +=(POINT point);
	void operator -=(POINT point);
	void SetPoint(int X, int Y);

// Operators returning CPointPtr values
	CPointPtr operator +(SIZE size) const;
	CPointPtr operator -(SIZE size) const;
	CPointPtr operator -() const;
	CPointPtr operator +(POINT point) const;

// Operators returning CSize values
//	CSize operator -(POINT point) const;

};


#define HISTORY_INSERT_CHAR	  		0x00000000L
#define HISTORY_BACK_SPACE	  		0x00000001L
#define HISTORY_DELETE_CHAR	  		0x00000002L
#define HISTORY_INSERT_STRING		0x00000003L
#define HISTORY_DELETE_STRING		0x00000005L
#define HISTORY_INSERT_TAB_SEL		0x00000006L
#define HISTORY_REVISION_RANGE		0x00000007L
#define HISTORY_SV_MODE				0x00000008L
#define HISTORY_REPLACE_STRING		0x00000009L
#define HISTORY_START_REPLACE		0x0000000aL
#define HISTORY_REORDER_COLUMN		0x0000000bL
#define HISTORY_SEL_ARRAY			0x0000000cL  // v17.6
#define HISTORY_CARET_POS			0x0000000dL
#define HISTORY_REPLACE_ARRAY		0x0000000eL  // v16.6
#define HISTORY_COMMENT				0x0000000fL
#define HISTORY_TYPE_MASK			0x0000000fL

#define HISTORY_GROUP_BEGINNING		0x00000100L  // v16.8
#define HISTORY_GROUP_CONVERT_SV	0x00000200L
#define HISTORY_GROUP_UNMODIFIED	0x00002000L
#define HISTORY_GROUP_TYPE_MASK		0x00001f00L

#define HISTORY_MODIFIED            0x00010000L
#define HISTORY_COMBINED			0x00020000L
#define HISTORY_CR_ONLY				0x00040000L
#define HISTORY_LF_ONLY				0x00080000L
#define HISTORY_SEL_BOX				0x00100000L
#define HISTORY_INSIDE_UNDO			0x00200000L
#define HISTORY_INSIDE_REDO			0x00400000L
#define HISTORY_SEPARATE_CRLF		0x00800000L  // v16.6
#define HISTORY_EMBEDDED_NL			0x01000000L
#define HISTORY_REPLACE_SAME_STRING 0x02000000L
#define HISTORY_IGNORE_DELETED_STRING 0x04000000L
#define HISTORY_CSV_EDIT_START		0x08000000L
#define HISTORY_SEL_LINE			0x10000000L  // v17.6
#define HISTORY_BOX_INSERT			0x20000000L  // v18.1
#define HISTORY_SEL_COL				0x40000000L  // v18.6

typedef struct _HISTORY_INFO {
	size_t  cbSize;
	UINT	nFlags;
	POINT_PTR ptTop;
	POINT_PTR ptBottom;
	UINT	nChar;
	LPCWSTR pszString;
} HISTORY_INFO;

#define TIM_REBAR			0x0001
#define TIM_CLIENT			0x0002
#define TIM_TITLE			0x0004
#define TIM_ID				0x0008
#define TIM_FLAGS			0x0010
#define TIM_STYLE			0x0020
#define TIM_MINCHILD		0x0040
#define TIM_CX				0x0080
#define TIM_CXIDEAL			0x0100
#define TIM_BAND			0x0200
#define TIM_PLUG_IN_CMD_ID	0x0400

typedef struct _TOOLBAR_INFO {
	size_t  cbSize;
	HWND    hwndRebar;
	HWND	hwndClient;
	LPCTSTR pszTitle;
	UINT	nMask;
	UINT	nID;
	UINT    nFlags;
	UINT	fStyle;
	UINT	cxMinChild;
	UINT	cyMinChild;
	UINT	cx;
	UINT	cxIdeal;
	UINT	nBand;
	WORD	wPlugInCmdID;
//	UINT	cyChild;
//	UINT	cyMaxChild;
//	UINT	cyIntegral;
} TOOLBAR_INFO;

typedef struct _REG_SET_VALUE_INFO {
	size_t	cbSize;
	DWORD	dwKey;
	LPCWSTR pszConfig;
	LPCWSTR pszValue;
	DWORD	dwType;
	const	BYTE* lpData;
	DWORD	cbData;
	DWORD	dwFlags;
} REG_SET_VALUE_INFO;

typedef struct _REG_QUERY_VALUE_INFO {
	size_t	cbSize;
	DWORD	dwKey;
	LPCWSTR pszConfig;
	LPCWSTR pszValue;
	DWORD	dwType;
	BYTE*   lpData;
	DWORD*	lpcbData;
	DWORD	dwFlags;
} REG_QUERY_VALUE_INFO;


typedef struct _PROCESS_INFO {
	size_t  cbSize;
	LPCWSTR pszAppName;
	LPCWSTR pszCmdLine;
	LPCWSTR pszDir;
	UINT	nFlags;
	UINT	nCP;
} PROCESS_INFO;

#define EE_FIRST                (WM_USER+0x400)
#define EE_GET_CMD_ID           (EE_FIRST+0)
  // (HINSTANCE)lParam = hInstance
  // returns (UINT)nCmdID

#ifdef EE_STRICT
inline UINT Editor_GetCmdID( HWND hwnd, HINSTANCE hInstance )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT)SNDMSG( hwnd, EE_GET_CMD_ID, 0, (LPARAM)hInstance );
}
#else
#define Editor_GetCmdID( hwnd, hInstance ) \
    (UINT)SNDMSG( (hwnd), EE_GET_CMD_ID, 0, (LPARAM)(HINSTANCE)(hInstance) )
#endif

#define EE_QUERY_STATUS         (EE_FIRST+1)
  // (UINT)wParam = nCmdID, (BOOL*)lParam = &bChecked
  // returns (BOOL)bEnabled

#ifdef EE_STRICT
inline BOOL Editor_QueryStatus( HWND hwnd, UINT nCmdID, BOOL* pbChecked )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( hwnd, EE_QUERY_STATUS, (WPARAM)nCmdID, (LPARAM)pbChecked );
}
#else
#define Editor_QueryStatus( hwnd, nCmdID, pbChecked ) \
    (BOOL)SNDMSG( (hwnd), EE_QUERY_STATUS, (WPARAM)(UINT)(nCmdID), (LPARAM)(BOOL*)pbChecked )
#endif

#define EE_UPDATE_TOOLBAR       (EE_FIRST+2)
  // (UINT)wParam = nCmdID

#ifdef EE_STRICT
inline void Editor_UpdateToolbar( HWND hwnd, UINT nCmdID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( hwnd, EE_UPDATE_TOOLBAR, (WPARAM)nCmdID, 0 );
}
#else
#define Editor_UpdateToolbar( hwnd, nCmdID ) \
    (void)SNDMSG( (hwnd), EE_UPDATE_TOOLBAR, (WPARAM)(UINT)(nCmdID), (LPARAM)0 )
#endif

#define EE_GET_SEL_TEXTA        (EE_FIRST+3)
  // (UINT_PTR)wParam = nBufferSize, (LPSTR)lParam = szBuffer
  // returns (UINT_PTR)nRequiredBufferSize

#ifdef EE_STRICT
inline UINT_PTR Editor_GetSelTextA( HWND hwnd, UINT_PTR nBufferSize, LPSTR szBuffer )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_SEL_TEXTA, (WPARAM)nBufferSize, (LPARAM)szBuffer );
}
#else
#define Editor_GetSelTextA( hwnd, nBufferSize, szBuffer ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_SEL_TEXTA, (WPARAM)(UINT_PTR)(nBufferSize), (LPARAM)(LPSTR)(szBuffer) )
#endif

#define EE_GET_SEL_TEXTW        (EE_FIRST+46)
  // (UINT_PTR)wParam = nBufferSize, (LPWSTR)lParam = szBuffer
  // returns (UINT_PTR)nRequiredBufferSize
#ifdef EE_STRICT
inline UINT_PTR Editor_GetSelTextW( HWND hwnd, UINT_PTR nBufferSize, LPWSTR szBuffer )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_SEL_TEXTW, (WPARAM)nBufferSize, (LPARAM)szBuffer );
}
#else
#define Editor_GetSelTextW( hwnd, nBufferSize, szBuffer ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_SEL_TEXTW, (WPARAM)(UINT_PTR)(nBufferSize), (LPARAM)(LPWSTR)(szBuffer) )
#endif

#define EE_GET_LINES            (EE_FIRST+4)
  // wParam = MAKEWPARAM( nLogical, iDoc+1 )
  // returns (UINT_PTR)nTotalLines

inline UINT_PTR Editor_DocGetLines( HWND hwnd, int iDoc, int nLogical )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_LINES, (WPARAM)MAKEWPARAM( nLogical, iDoc+1 ), (LPARAM)0 );
}

#ifdef EE_STRICT
inline UINT_PTR Editor_GetLines( HWND hwnd, int nLogical )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_LINES, (WPARAM)(int)(nLogical), (LPARAM)0 );
}
#else
#define Editor_GetLines( hwnd, nLogical ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_LINES, (WPARAM)(int)(nLogical), (LPARAM)0 )
#endif

#define EE_GET_LINEA            (EE_FIRST+5)
  // (GET_LINE_INFO*)wParam = pGetLineInfo, (LPSTR)lParam = szString
  // returns (UINT_PTR)nRequiredBufferSize

#ifdef EE_STRICT
inline UINT_PTR Editor_GetLineA( HWND hwnd, GET_LINE_INFO* pGetLineInfo, LPSTR szString )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_LINEA, (WPARAM)(GET_LINE_INFO*)(pGetLineInfo), (LPARAM)(LPSTR)(szString) );
}
#else
#define Editor_GetLineA( hwnd, pGetLineInfo, szString ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_LINEA, (WPARAM)(GET_LINE_INFO*)(pGetLineInfo), (LPARAM)(LPSTR)(szString) )
#endif

#define EE_GET_LINEW            (EE_FIRST+47)
  // (GET_LINE_INFO*)wParam = pGetLineInfo, (LPWSTR)lParam = szString
  // returns (UINT_PTR)nRequiredBufferSize

#ifdef EE_STRICT
inline UINT_PTR Editor_GetLineW( HWND hwnd, GET_LINE_INFO* pGetLineInfo, LPWSTR szString )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_LINEW, (WPARAM)(GET_LINE_INFO*)(pGetLineInfo), (LPARAM)(LPWSTR)(szString) );
}
#else
#define Editor_GetLineW( hwnd, pGetLineInfo, szString ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_LINEW, (WPARAM)(GET_LINE_INFO*)(pGetLineInfo), (LPARAM)(LPWSTR)(szString) )
#endif

#define EE_GET_CARET_POS        (EE_FIRST+6)
  // (int)wParam = nLogical, (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_GetCaretPos( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( hwnd, EE_GET_CARET_POS, (WPARAM)nLogical, (LPARAM)pptPos );
}
#else
#define Editor_GetCaretPos( hwnd, nLogical, pptPos ) \
    (void)SNDMSG( (hwnd), EE_GET_CARET_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_DEV_TO_VIEW          (EE_FIRST+7)
  // (POINT_PTR*)wParam = pptDev, (POINT_PTR*)lParam = pptView

#ifdef EE_STRICT
inline void Editor_DevToView( HWND hwnd, POINT_PTR* pptDev, POINT_PTR* pptView )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_DEV_TO_VIEW, (WPARAM)(POINT_PTR*)(pptDev), (LPARAM)(POINT_PTR*)(pptView) );
}
#else
#define Editor_DevToView( hwnd, pptDev, pptView ) \
    (void)SNDMSG( (hwnd), EE_DEV_TO_VIEW, (WPARAM)(POINT_PTR*)(pptDev), (LPARAM)(POINT_PTR*)(pptView) )
#endif

#define EE_GET_PAGE_SIZE        (EE_FIRST+8)
  // (SIZE_PTR*)lParam = psizePage

#ifdef EE_STRICT
inline void Editor_GetPageSize( HWND hwnd, SIZE_PTR* psizePage )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_PAGE_SIZE, (WPARAM)0, (LPARAM)(SIZE_PTR*)(psizePage) );
}
#else
#define Editor_GetPageSize( hwnd, psizePage ) \
    (void)SNDMSG( (hwnd), EE_GET_PAGE_SIZE, (WPARAM)0, (LPARAM)(SIZE_PTR*)(psizePage) )
#endif

#define EE_GET_SCROLL_POS       (EE_FIRST+9)
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_GetScrollPos( HWND hwnd, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_SCROLL_POS, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_GetScrollPos( hwnd, pptPos ) \
    (void)SNDMSG( (hwnd), EE_GET_SCROLL_POS, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_LINE_FROM_CHAR       (EE_FIRST+10)
  // (int)wParam = nLogical, (UINT_PTR)lParam = nSerialIndex
  // returns (UINT_PTR)yLine

#ifdef EE_STRICT
inline UINT_PTR Editor_LineFromChar( HWND hwnd, int nLogical, UINT_PTR nSerialIndex )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_LINE_FROM_CHAR, (WPARAM)(int)(nLogical), (LPARAM)(UINT_PTR)(nSerialIndex) );
}
#else
#define Editor_LineFromChar( hwnd, nLogical, nSerialIndex ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_LINE_FROM_CHAR, (WPARAM)(int)(nLogical), (LPARAM)(UINT_PTR)(nSerialIndex) )
#endif

#define EE_LINE_INDEX           (EE_FIRST+11)
  // (BOOL)wParam = bLogical, (UINT_PTR)lParam = yLine
  // returns (UINT_PTR)nSerialIndex

#ifdef EE_STRICT
inline UINT_PTR Editor_LineIndex( HWND hwnd, BOOL bLogical, UINT_PTR yLine )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_LINE_INDEX, (WPARAM)(BOOL)(bLogical), (LPARAM)(UINT_PTR)(yLine) );
}
#else
#define Editor_LineIndex( hwnd, bLogical, yLine ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_LINE_INDEX, (WPARAM)(BOOL)(bLogical), (LPARAM)(UINT_PTR)(yLine) )
#endif

#define EE_LOAD_FILEA           (EE_FIRST+12)
  // (LOAD_FILE_INFO_EX*)wParam = plfi
  // (LPCSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_LoadFileA( HWND hwnd, LOAD_FILE_INFO_EX* plfi, LPCSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEA, (WPARAM)plfi, (LPARAM)(LPCSTR)(szFileName) );
}
#else
#define Editor_LoadFileA( hwnd, plfi, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEA, (WPARAM)(LOAD_FILE_INFO_EX*)plfi, (LPARAM)(LPCSTR)(szFileName) )
#endif

#define EE_LOAD_FILEW           (EE_FIRST+48)
  // (LOAD_FILE_INFO_EX*)wParam = plfi
  // (LPCWSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_LoadFileW( HWND hwnd, LOAD_FILE_INFO_EX* plfi, LPCWSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEW, (WPARAM)plfi, (LPARAM)(LPCWSTR)(szFileName) );
}
#else
#define Editor_LoadFileW( hwnd, plfi, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEW, (WPARAM)(LOAD_FILE_INFO_EX*)plfi, (LPARAM)(LPCWSTR)(szFileName) )
#endif

#ifdef EE_STRICT
inline BOOL Editor_LoadFileW( HWND hwnd, LOAD_FILE_INFO_EX_V2* plfi, LPCWSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEW, (WPARAM)plfi, (LPARAM)(LPCWSTR)(szFileName) );
}
#else
#define Editor_LoadFileW( hwnd, plfi, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_LOAD_FILEW, (WPARAM)(LOAD_FILE_INFO_EX_V2*)plfi, (LPARAM)(LPCWSTR)(szFileName) )
#endif

#define EE_LOGICAL_TO_SERIAL    (EE_FIRST+13)
  // (POINT_PTR*)lParam = pptLogical
  // returns (UINT_PTR)nSerialIndex

#ifdef EE_STRICT
inline UINT_PTR Editor_LogicalToSerial( HWND hwnd, POINT_PTR* pptLogical )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_LOGICAL_TO_SERIAL, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptLogical) );
}
#else
#define Editor_LogicalToSerial( hwnd, pptLogical ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_LOGICAL_TO_SERIAL, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptLogical) )
#endif

#define EE_LOGICAL_TO_VIEW      (EE_FIRST+14)
  // (POINT_PTR*)wParam = pptLogical, (POINT_PTR*)lParam = pptView

#ifdef EE_STRICT
inline void Editor_LogicalToView( HWND hwnd, POINT_PTR* pptLogical, POINT_PTR* pptView )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_LOGICAL_TO_VIEW, (WPARAM)(POINT_PTR*)(pptLogical), (LPARAM)(POINT_PTR*)(pptView) );
}
#else
#define Editor_LogicalToView( hwnd, pptLogical, pptView ) \
    (void)SNDMSG( (hwnd), EE_LOGICAL_TO_VIEW, (WPARAM)(POINT_PTR*)(pptLogical), (LPARAM)(POINT_PTR*)(pptView) )
#endif

#define EE_SAVE_FILEA           (EE_FIRST+16)
  // (BOOL)wParam = bReplace, (LPSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_SaveFileA( HWND hwnd, BOOL bReplace, LPSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEA, (WPARAM)(BOOL)(bReplace), (LPARAM)(LPSTR)(szFileName) );
}
#else
#define Editor_SaveFileA( hwnd, bReplace, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEA, (WPARAM)(BOOL)(bReplace), (LPARAM)(LPSTR)(szFileName) )
#endif

#ifdef EE_STRICT
inline BOOL Editor_DocSaveFileA( HWND hwnd, int iDoc, BOOL bReplace, LPSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEA, MAKEWPARAM((bReplace), (iDoc)+1), (LPARAM)(LPSTR)(szFileName) );
}
#else
#define Editor_DocSaveFileA( hwnd, iDoc, bReplace, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEA, MAKEWPARAM((bReplace), (iDoc)+1), (LPARAM)(LPSTR)(szFileName) )
#endif

#define EE_SAVE_FILEW           (EE_FIRST+49)
  // (BOOL)wParam = bReplace, (LPWSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_SaveFileW( HWND hwnd, BOOL bReplace, LPWSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEW, (WPARAM)(BOOL)(bReplace), (LPARAM)(LPWSTR)(szFileName) );
}
#else
#define Editor_SaveFileW( hwnd, bReplace, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEW, (WPARAM)(BOOL)(bReplace), (LPARAM)(LPWSTR)(szFileName) )
#endif

#ifdef EE_STRICT
inline BOOL Editor_DocSaveFileW( HWND hwnd, int iDoc, BOOL bReplace, LPWSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEW, MAKEWPARAM((bReplace), (iDoc)+1), (LPARAM)(LPWSTR)(szFileName) );
}
#else
#define Editor_DocSaveFileW( hwnd, iDoc, bReplace, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_SAVE_FILEW, MAKEWPARAM((bReplace), (iDoc)+1), (LPARAM)(LPWSTR)(szFileName) )
#endif

#define EE_SERIAL_TO_LOGICAL    (EE_FIRST+17)
  // (UINT_PTR)wParam = nSerial, (POINT_PTR*)lParam = pptLogical

#ifdef EE_STRICT
inline void Editor_SerialToLogical( HWND hwnd, UINT_PTR nSerial, POINT_PTR* pptLogical )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SERIAL_TO_LOGICAL, (WPARAM)(UINT_PTR)(nSerial), (LPARAM)(POINT_PTR*)(pptLogical) );
}
#else
#define Editor_SerialToLogical( hwnd, nSerial, pptLogical ) \
    (void)SNDMSG( (hwnd), EE_SERIAL_TO_LOGICAL, (WPARAM)(UINT_PTR)(nSerial), (LPARAM)(POINT_PTR*)(pptLogical) )
#endif

#define EE_SET_CARET_POS        (EE_FIRST+18)
  // wParam = MAKEWPARAM( nLogical, bExtend )
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_SetCaretPos( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_CARET_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_SetCaretPos( hwnd, nLogical, pptPos ) \
    (void)SNDMSG( (hwnd), EE_SET_CARET_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#ifdef EE_STRICT
inline HRESULT Editor_SetCaretPosEx( HWND hwnd, int nLogical, POINT_PTR* pptPos, BOOL bExtend )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (HRESULT)SNDMSG( (hwnd), EE_SET_CARET_POS, MAKEWPARAM(nLogical, bExtend), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_SetCaretPosEx( hwnd, nLogical, pptPos, bExtend ) \
    (HRESULT)SNDMSG( (hwnd), EE_SET_CARET_POS, MAKEWPARAM(nLogical, bExtend), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_SET_SCROLL_POS       (EE_FIRST+19)
  // (BOOL)wParam = bCanMoveCursor
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_SetScrollPos( HWND hwnd, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_SCROLL_POS, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_SetScrollPos( hwnd, pptPos ) \
    (void)SNDMSG( (hwnd), EE_SET_SCROLL_POS, (WPARAM)0, (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#ifdef EE_STRICT
inline void Editor_SetScrollPosEx( HWND hwnd, POINT_PTR* pptPos, BOOL bCanMoveCursor )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_SCROLL_POS, (WPARAM)(BOOL)bCanMoveCursor, (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_SetScrollPosEx( hwnd, pptPos, bCanMoveCursor ) \
    (void)SNDMSG( (hwnd), EE_SET_SCROLL_POS, (WPARAM)(BOOL)bCanMoveCursor, (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_VIEW_TO_DEV          (EE_FIRST+20)
  // (POINT_PTR*)wParam = pptView, (POINT_PTR*)lParam = pptDev

#ifdef EE_STRICT
inline void Editor_ViewToDev( HWND hwnd, POINT_PTR* pptView, POINT_PTR* pptDev )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_VIEW_TO_DEV, (WPARAM)(POINT_PTR*)(pptView), (LPARAM)(POINT_PTR*)(pptDev) );
}
#else
#define Editor_ViewToDev( hwnd, pptView, pptDev ) \
    (void)SNDMSG( (hwnd), EE_VIEW_TO_DEV, (WPARAM)(POINT_PTR*)(pptView), (LPARAM)(POINT_PTR*)(pptDev) )
#endif

#define EE_VIEW_TO_LOGICAL      (EE_FIRST+21)
  // (POINT*)wParam = pptView, (POINT*)lParam = pptLogical

#ifdef EE_STRICT
inline void Editor_ViewToLogical( HWND hwnd, const POINT_PTR* pptView, POINT_PTR* pptLogical )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_VIEW_TO_LOGICAL, (WPARAM)(const POINT_PTR*)(pptView), (LPARAM)(POINT_PTR*)(pptLogical ) );
}
#else
#define Editor_ViewToLogical( hwnd, pptView, pptLogical ) \
    (void)SNDMSG( (hwnd), EE_VIEW_TO_LOGICAL, (WPARAM)(POINT_PTR*)(pptView), (LPARAM)(POINT_PTR*)(pptLogical ) )
#endif

#define EE_EXEC_COMMAND         (EE_FIRST+22)
  // (UINT)wParam = nCmdID

#ifdef EE_STRICT
inline BOOL Editor_ExecCommand( HWND hwnd, UINT nCmdID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_EXEC_COMMAND, (WPARAM)(UINT)(nCmdID), (LPARAM)0 );
}
#else
#define Editor_ExecCommand( hwnd, nCmdID ) \
    (BOOL)SNDMSG( (hwnd), EE_EXEC_COMMAND, (WPARAM)(UINT)(nCmdID), (LPARAM)0 )
#endif

#define EE_GET_MODIFIED         (EE_FIRST+23)
  // returns (BOOL)bModified

#ifdef EE_STRICT
inline BOOL Editor_GetModified( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_GET_MODIFIED, (WPARAM)0, (LPARAM)0 );
}
#else
#define Editor_GetModified( hwnd ) \
    (BOOL)SNDMSG( (hwnd), EE_GET_MODIFIED, (WPARAM)0, (LPARAM)0 )
#endif

#ifdef EE_STRICT
inline BOOL Editor_DocGetModified( HWND hwnd, int iDoc )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_GET_MODIFIED, MAKEWPARAM(0, (iDoc)+1), (LPARAM)0 );
}
#else
#define Editor_DocGetModified( hwnd, iDoc ) \
    (BOOL)SNDMSG( (hwnd), EE_GET_MODIFIED, MAKEWPARAM(0, (iDoc)+1), (LPARAM)0 )
#endif

#define EE_SET_MODIFIED         (EE_FIRST+24)
  // (BOOL)wParam = bModified

#ifdef EE_STRICT
inline void Editor_SetModified( HWND hwnd, BOOL bModified )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    (void)SNDMSG( (hwnd), EE_SET_MODIFIED, (WPARAM)(BOOL)(bModified), (LPARAM)0 );
}
#else
#define Editor_SetModified( hwnd, bModified ) \
    (void)SNDMSG( (hwnd), EE_SET_MODIFIED, (WPARAM)(BOOL)(bModified), (LPARAM)0 )
#endif

#define EE_GET_SEL_START        (EE_FIRST+26)
  // (int)wParam = nLogical
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_GetSelStart( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_SEL_START, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_GetSelStart( hwnd, nLogical, pptPos ) \
    (void)SNDMSG( (hwnd), EE_GET_SEL_START, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_GET_SEL_END          (EE_FIRST+27)
  // (int)wParam = nLogical
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_GetSelEnd( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_SEL_END, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_GetSelEnd( hwnd, nLogical, pptPos ) \
    (void)SNDMSG( (hwnd), EE_GET_SEL_END, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_SET_SEL_LENGTH       (EE_FIRST+28)
  // (UINT_PTR)wParam = nLen

#ifdef EE_STRICT
inline void Editor_SetSelLength( HWND hwnd, UINT_PTR nLen )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    (void)SNDMSG( (hwnd), EE_SET_SEL_LENGTH, (WPARAM)(UINT_PTR)(nLen), (LPARAM)0 );
}
#else
#define Editor_SetSelLength( hwnd, nLen ) \
    (void)SNDMSG( (hwnd), EE_SET_SEL_LENGTH, (WPARAM)(UINT_PTR)(nLen), (LPARAM)0 )
#endif

#define EE_GET_CONFIGA          (EE_FIRST+29)
  // (LPSTR)lParam = szConfigName

#ifdef EE_STRICT
inline void Editor_GetConfigA( HWND hwnd, LPSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_CONFIGA, (WPARAM)0, (LPARAM)(LPSTR)(szConfigName) );
}
#else
#define Editor_GetConfigA( hwnd, szConfigName ) \
    (void)SNDMSG( (hwnd), EE_GET_CONFIGA, (WPARAM)0, (LPARAM)(LPSTR)(szConfigName) )
#endif

#ifdef EE_STRICT
inline void Editor_DocGetConfigA( HWND hwnd, int iDoc, LPSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_CONFIGA, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPSTR)(szConfigName) );
}
#else
#define Editor_DocGetConfigA( hwnd, iDoc, szConfigName ) \
    (void)SNDMSG( (hwnd), EE_GET_CONFIGA, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPSTR)(szConfigName) )
#endif

#define EE_GET_CONFIGW          (EE_FIRST+50)
  // (LPWSTR)lParam = szConfigName

#ifdef EE_STRICT
inline void Editor_GetConfigW( HWND hwnd, LPWSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_CONFIGW, (WPARAM)0, (LPARAM)(LPWSTR)(szConfigName) );
}
#else
#define Editor_GetConfigW( hwnd, szConfigName ) \
    (void)SNDMSG( (hwnd), EE_GET_CONFIGW, (WPARAM)0, (LPARAM)(LPWSTR)(szConfigName) )
#endif

#ifdef EE_STRICT
inline void Editor_DocGetConfigW( HWND hwnd, int iDoc, LPWSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_CONFIGW, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPWSTR)(szConfigName) );
}
#else
#define Editor_DocGetConfigW( hwnd, iDoc, szConfigName ) \
    (void)SNDMSG( (hwnd), EE_GET_CONFIGW, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPWSTR)(szConfigName) )
#endif

#define EE_SET_CONFIGA          (EE_FIRST+30)
  // (LPCSTR)lParam = szConfigName

#ifdef EE_STRICT
inline BOOL Editor_SetConfigA( HWND hwnd, LPSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGA, (WPARAM)0, (LPARAM)(LPSTR)(szConfigName) );
}
#else
#define Editor_SetConfigA( hwnd, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGA, (WPARAM)0, (LPARAM)(LPSTR)(szConfigName) )
#endif

#ifdef EE_STRICT
inline BOOL Editor_DocSetConfigA( HWND hwnd, int iDoc, LPSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGA, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPSTR)(szConfigName) );
}
#else
#define Editor_DocSetConfigA( hwnd, iDoc, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGA, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPSTR)(szConfigName) )
#endif

#define EE_SET_CONFIGW          (EE_FIRST+51)
  // (LPCWSTR)lParam = szConfigName

#ifdef EE_STRICT
inline BOOL Editor_SetConfigW( HWND hwnd, LPWSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGW, (WPARAM)0, (LPARAM)(LPWSTR)(szConfigName) );
}
#else
#define Editor_SetConfigW( hwnd, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGW, (WPARAM)0, (LPARAM)(LPWSTR)(szConfigName) )
#endif

#ifdef EE_STRICT
inline BOOL Editor_DocSetConfigW( HWND hwnd, int iDoc, LPWSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGW, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPWSTR)(szConfigName) );
}
#else
#define Editor_DocSetConfigW( hwnd, iDoc, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_SET_CONFIGW, (WPARAM)MAKEWPARAM(0, (iDoc)+1), (LPARAM)(LPWSTR)(szConfigName) )
#endif

#define EE_EMPTY_UNDO_BUFFER    (EE_FIRST+31)

#ifdef EE_STRICT
inline void Editor_EmptyUndoBuffer( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_EMPTY_UNDO_BUFFER, (WPARAM)0, (LPARAM)0 );
}
#else
#define Editor_EmptyUndoBuffer( hwnd ) \
    (void)SNDMSG( (hwnd), EE_EMPTY_UNDO_BUFFER, (WPARAM)0, (LPARAM)0 )
#endif

#define OVERWRITE_PER_PROP		0
#define OVERWRITE_INSERT		1
#define OVERWRITE_OVERWRITE		2
#define OVERWRITE_MASK			3
#define KEEP_SOURCE_RETURN_TYPE	0x00000000
#define KEEP_DEST_RETURN_TYPE	0x00000010

#define EE_INSERT_STRINGA       (EE_FIRST+32)
  // (int)wParam = nInsertType
  // (LPCSTR)lParam = szString

inline void Editor_InsertStringA( HWND hwnd, LPCSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_INSERT_STRINGA, (WPARAM)OVERWRITE_PER_PROP | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCSTR)(szString) );
}

inline void Editor_InsertA( HWND hwnd, LPCSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_INSERT_STRINGA, (WPARAM)OVERWRITE_INSERT | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCSTR)(szString) );
}

inline void Editor_OverwriteA( HWND hwnd, LPCSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_INSERT_STRINGA, (WPARAM)OVERWRITE_OVERWRITE | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCSTR)(szString) );
}

#define EE_INSERT_STRINGW       (EE_FIRST+52)
  // (int)wParam = nInsertType | bKeepDestReturnType
  // (LPCWSTR)lParam = szString

inline void Editor_InsertStringW( HWND hwnd, LPCWSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_INSERT_STRINGW, (WPARAM)OVERWRITE_PER_PROP | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCWSTR)(szString) );
}

inline void Editor_InsertW( HWND hwnd, LPCWSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	SNDMSG( (hwnd), EE_INSERT_STRINGW, (WPARAM)OVERWRITE_INSERT | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCWSTR)(szString) );
}

inline void Editor_OverwriteW( HWND hwnd, LPCWSTR szString, bool bKeepDestReturnType = false )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_INSERT_STRINGW, (WPARAM)OVERWRITE_OVERWRITE | (bKeepDestReturnType ? KEEP_DEST_RETURN_TYPE : KEEP_SOURCE_RETURN_TYPE), (LPARAM)(LPCWSTR)(szString) );
}

#define EE_SET_SEL_VIEW         (EE_FIRST+33)
  // (POINT_PTR*)wParam = pptSelStart, (POINT_PTR*)lParam = pptSelEnd

#ifdef EE_STRICT
inline void Editor_SetSelView( HWND hwnd, POINT_PTR* pptSelStart, POINT_PTR* pptSelEnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_SEL_VIEW, (WPARAM)(POINT_PTR*)(pptSelStart), (LPARAM)(POINT_PTR*)(pptSelEnd) );
}
#else
#define Editor_SetSelView( hwnd, pptSelStart, pptSelEnd ) \
    (void)SNDMSG( (hwnd), EE_SET_SEL_VIEW, (WPARAM)(POINT_PTR*)(pptSelStart), (LPARAM)(POINT_PTR*)(pptSelEnd) )
#endif

#define EE_FINDA                (EE_FIRST+34)
  // (UINT)wParam = nFlags, (LPCSTR)lParam = szFind
  // returns (BOOL)bSuccess

#ifdef EE_STRICT
inline BOOL Editor_FindA( HWND hwnd, UINT nFlags, LPCSTR szFind )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_FINDA, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCSTR)(szFind) );
}
#else
#define Editor_FindA( hwnd, nFlags, szFind ) \
    (BOOL)SNDMSG( (hwnd), EE_FINDA, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCSTR)(szFind) )
#endif

#define EE_FINDW                (EE_FIRST+53)
  // (UINT)wParam = nFlags, (LPCWSTR)lParam = szFind
  // returns (int)nCount

#ifdef EE_STRICT
inline int Editor_FindW( HWND hwnd, UINT nFlags, LPCWSTR szFind )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_FINDW, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCWSTR)(szFind) );
}
#else
#define Editor_FindW( hwnd, nFlags, szFind ) \
    (int)SNDMSG( (hwnd), EE_FINDW, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCWSTR)(szFind) )
#endif

#define EE_REPLACEA             (EE_FIRST+35)
  // (UINT)wParam = nFlags, (LPCWSTR)lParam = szFindReplace
  // returns (int)nCount

#ifdef EE_STRICT
inline int Editor_ReplaceA( HWND hwnd, UINT nFlags, LPCSTR szFindReplace )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_REPLACEA, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCSTR)(szFindReplace) );
}
#else
#define Editor_ReplaceA( hwnd, nFlags, szFindReplace ) \
    (int)SNDMSG( (hwnd), EE_REPLACEA, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCSTR)(szFindReplace) )
#endif

#define EE_REPLACEW             (EE_FIRST+54)
  // (UINT)wParam = nFlags, (LPCWSTR)lParam = szFindReplace
  // returns (int)nCount

#ifdef EE_STRICT
inline int Editor_ReplaceW( HWND hwnd, UINT nFlags, LPCWSTR szFindReplace )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_REPLACEW, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCWSTR)(szFindReplace) );
}
#else
#define Editor_ReplaceW( hwnd, nFlags, szFindReplace ) \
    (int)SNDMSG( (hwnd), EE_REPLACEW, (WPARAM)(UINT)(nFlags), (LPARAM)(LPCWSTR)(szFindReplace) )
#endif

#define EE_LOAD_CONFIGA         (EE_FIRST+36)
  // (LPCSTR)lParam = szConfigName

#ifdef EE_STRICT
inline BOOL Editor_LoadConfigA( HWND hwnd, LPCSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_LOAD_CONFIGA, (WPARAM)0, (LPARAM)(LPCSTR)(szConfigName) );
}
#else
#define Editor_LoadConfigA( hwnd, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_LOAD_CONFIGA, (WPARAM)0, (LPARAM)(LPCSTR)(szConfigName) )
#endif

#define EE_LOAD_CONFIGW         (EE_FIRST+55)
  // (LPCWSTR)lParam = szConfigName

#ifdef EE_STRICT
inline BOOL Editor_LoadConfigW( HWND hwnd, LPCWSTR szConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_LOAD_CONFIGW, (WPARAM)0, (LPARAM)(LPCWSTR)(szConfigName) );
}
#else
#define Editor_LoadConfigW( hwnd, szConfigName ) \
    (BOOL)SNDMSG( (hwnd), EE_LOAD_CONFIGW, (WPARAM)0, (LPARAM)(LPCWSTR)(szConfigName) )
#endif

#define EE_SET_STATUSA          (EE_FIRST+37)
  // (LPCSTR)lParam = szStatus

#ifdef EE_STRICT
inline void Editor_SetStatusA( HWND hwnd, LPCSTR szStatus )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_STATUSA, (WPARAM)0, (LPARAM)(LPCSTR)(szStatus) );
}
#else
#define Editor_SetStatusA( hwnd, szStatus ) \
    (void)SNDMSG( (hwnd), EE_SET_STATUSA, (WPARAM)0, (LPARAM)(LPCSTR)(szStatus) )
#endif

#define EE_SET_STATUSW          (EE_FIRST+56)
  // (LPCWSTR)lParam = szStatus

#ifdef EE_STRICT
inline void Editor_SetStatusW( HWND hwnd, LPCWSTR szStatus )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_STATUSW, (WPARAM)0, (LPARAM)(LPCWSTR)(szStatus) );
}
#else
#define Editor_SetStatusW( hwnd, szStatus ) \
    (void)SNDMSG( (hwnd), EE_SET_STATUSW, (WPARAM)0, (LPARAM)(LPCWSTR)(szStatus) )
#endif

#define EE_CONVERT              (EE_FIRST+38)
  // (UINT)wParam = nFlags

#ifdef EE_STRICT
inline BOOL Editor_Convert( HWND hwnd, UINT nFlags, LPCWSTR szChars = NULL )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_CONVERT, (WPARAM)(UINT)(nFlags), (LPARAM)szChars );
}
#else
#define Editor_Convert( hwnd, nFlags ) \
    (BOOL)SNDMSG( (hwnd), EE_CONVERT, (WPARAM)(UINT)(nFlags), (LPARAM)0 )
#endif

#define EE_GET_MARGIN           (EE_FIRST+39)
  // returns (UINT_PTR)nMaxMargin

#ifdef EE_STRICT
inline UINT_PTR Editor_GetMargin( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_MARGIN, (WPARAM)0, (LPARAM)0 );
}
#else
#define Editor_GetMargin( hwnd ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_MARGIN, (WPARAM)0, (LPARAM)0 )
#endif

#define EE_GET_VERSION          (EE_FIRST+40)
  // (UINT*)wParam = pnProductType
  // returns (UINT)nVersion

#ifdef EE_STRICT
inline UINT Editor_GetVersion( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT)SNDMSG( (hwnd), EE_GET_VERSION, (WPARAM)0, (LPARAM)0 );
}
#else
#define Editor_GetVersion( hwnd ) \
    (UINT)SNDMSG( (hwnd), EE_GET_VERSION, (WPARAM)0, (LPARAM)0 )
#endif

#ifdef EE_STRICT
inline UINT Editor_GetVersionEx( HWND hwnd, UINT* pnProductType )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT)SNDMSG( (hwnd), EE_GET_VERSION, (WPARAM)pnProductType, (LPARAM)0 );
}
#else
#define Editor_GetVersionEx( hwnd, pnProductType ) \
    (UINT)SNDMSG( (hwnd), EE_GET_VERSION, (WPARAM)(UINT*)pnProductType, (LPARAM)0 )
#endif

#define VERSION_FREE			4
#define VERSION_LITE            3
#define VERSION_PRO             2
#define VERSION_STD             1

#define EE_GET_REF              (EE_FIRST+41)
  // (ATOM)lParam = atom
  // return (int)nRef

#ifdef EE_STRICT
inline int Editor_GetRef( HWND hwnd, ATOM atom )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_GET_REF, (WPARAM)0, (LPARAM)(ATOM)atom );
}
#else
#define Editor_GetRef( hwnd, atom ) \
    (int)SNDMSG( (hwnd), EE_GET_REF, (WPARAM)0, (LPARAM)(ATOM)atom )
#endif

#define EE_ADD_REF              (EE_FIRST+42)
  // (HINSTANCE)lParam = hInstance
  // return (int)nRef

#ifdef EE_STRICT
inline int Editor_AddRef( HWND hwnd, HINSTANCE hInstance )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_ADD_REF, (WPARAM)0, (LPARAM)(HINSTANCE)hInstance );
}
#else
#define Editor_AddRef( hwnd, hInstance ) \
    (int)SNDMSG( (hwnd), EE_ADD_REF, (WPARAM)0, (LPARAM)(HINSTANCE)hInstance )
#endif
 
#define EE_RELEASE              (EE_FIRST+43)
  // (HINSTANCE)lParam = hInstance
  // return (int)nRef
 
#ifdef EE_STRICT
inline int Editor_Release( HWND hwnd, HINSTANCE hInstance )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_RELEASE, (WPARAM)0, (LPARAM)(HINSTANCE)hInstance );
}
#else
#define Editor_Release( hwnd, hInstance ) \
    (int)SNDMSG( (hwnd), EE_RELEASE, (WPARAM)0, (LPARAM)(HINSTANCE)hInstance )
#endif

#define EE_REDRAW               (EE_FIRST+44)
  // (BOOL)wParam = bRedraw

#ifdef EE_STRICT
inline void Editor_Redraw( HWND hwnd, BOOL bRedraw )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_REDRAW, (WPARAM)bRedraw, (LPARAM)0 );
}
#else
#define Editor_Redraw( hwnd, bRedraw ) \
    (void)SNDMSG( (hwnd), EE_REDRAW, (WPARAM)(BOOL)bRedraw, (LPARAM)0 )
#endif

#define EE_GET_SEL_TYPE         (EE_FIRST+45)
  // (BOOL)wParam = bNeedAlways
  // return (int)nSelType

#ifdef EE_STRICT
inline int Editor_GetSelType( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_GET_SEL_TYPE, (WPARAM)0, (LPARAM)0 );
}

inline int Editor_GetSelTypeEx( HWND hwnd, BOOL bNeedAlways )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_GET_SEL_TYPE, (WPARAM)(BOOL)bNeedAlways, (LPARAM)0 );
}
#else
#define Editor_GetSelType( hwnd ) \
    (int)SNDMSG( (hwnd), EE_GET_SEL_TYPE, (WPARAM)0, (LPARAM)0 )

#define Editor_GetSelTypeEx( hwnd, bNeedAlways ) \
    (int)SNDMSG( (hwnd), EE_GET_SEL_TYPE, (WPARAM)(BOOL)bNeedAlways, (LPARAM)0 )
#endif

#define EE_IS_CHAR_HALF_OR_FULL (EE_FIRST+57)
  // 1.
  // (WCHAR)wParam = ch
  // (int)lParam = 0
  // 2.
  // (UINT)wParam = nScaler
  // (int)lParam = -1
  // 3.
  // (INT_PTR)wParam = cchStr
  // (LPCWSTR)lParam = pStr   
  // return (int)nWidth


inline int Editor_IsCharHalfOrFull( HWND hwnd, WCHAR ch )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_IS_CHAR_HALF_OR_FULL, (WPARAM)ch, (LPARAM)0 );
}

inline int Editor_IsCharHalfOrFull( HWND hwnd, UINT ch )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (int)SNDMSG( (hwnd), EE_IS_CHAR_HALF_OR_FULL, (WPARAM)ch, (LPARAM)-1 );
}

inline INT_PTR Editor_IsCharHalfOrFull( HWND hwnd, LPCWSTR pStr, INT_PTR cchStr )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (INT_PTR)SNDMSG( (hwnd), EE_IS_CHAR_HALF_OR_FULL, (WPARAM)cchStr, (LPARAM)pStr );
}

#define EE_INFO                 (EE_FIRST+58)
  // (int)wParam = nCmd
  // lParam = lParam
  // return lResult

#ifdef EE_STRICT
inline LRESULT Editor_Info( HWND hwnd, WPARAM nCmd, LPARAM lParam )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (LRESULT)SNDMSG( (hwnd), EE_INFO, (WPARAM)nCmd, (LPARAM)lParam );
}
#else
#define Editor_Info( hwnd, nCmd, lParam ) \
    (LRESULT)SNDMSG( (hwnd), EE_INFO, (WPARAM)nCmd, (LPARAM)lParam )
#endif

#ifdef EE_STRICT
inline LRESULT Editor_DocInfo( HWND hwnd, int iDoc, WPARAM nCmd, LPARAM lParam )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (LRESULT)SNDMSG( (hwnd), EE_INFO, (WPARAM)MAKEWPARAM((nCmd),(iDoc+1)), (LPARAM)(lParam) );
}
#else
#define Editor_DocInfo( hwnd, iDoc, nCmd, lParam ) \
    (LRESULT)SNDMSG( (hwnd), EE_INFO, (WPARAM)MAKEWPARAM((nCmd),(iDoc+1)), (LPARAM)(lParam) )
#endif

#define EE_FREE                 (EE_FIRST+59)
  // (ATOM)lParam = atom
  // return (BOOL)bSuccess

#ifdef EE_STRICT
inline BOOL Editor_Free( HWND hwnd, ATOM atom )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_FREE, (WPARAM)0, (LPARAM)(ATOM)atom );
}
#else
#define Editor_Free( hwnd, atom ) \
    (BOOL)SNDMSG( (hwnd), EE_FREE, (WPARAM)0, (LPARAM)(ATOM)atom )
#endif

#define EE_SET_SEL_TYPE         (EE_FIRST+60)
  // (BOOL)wParam = bNeedAlways
  // (UINT)lParam = nSelType

#ifdef EE_STRICT
inline void Editor_SetSelType( HWND hwnd, UINT nSelType )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_SEL_TYPE, (WPARAM)0, (LPARAM)nSelType );
}

inline void Editor_SetSelTypeEx( HWND hwnd, BOOL bNeedAlways, UINT nSelType )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_SET_SEL_TYPE, (WPARAM)(BOOL)bNeedAlways, (LPARAM)nSelType );
}
#else
#define Editor_SetSelType( hwnd, nSelType ) \
    (void)SNDMSG( (hwnd), EE_SET_SEL_TYPE, (WPARAM)0, (LPARAM)nSelType )
#define Editor_SetSelTypeEx( hwnd, nSelType ) \
    (void)SNDMSG( (hwnd), EE_SET_SEL_TYPE_EX, (WPARAM)(BOOL)bNeedAlways, (LPARAM)nSelType )
#endif

#define EE_GET_STATUSA          (EE_FIRST+61)
  // (UINT_PTR)wParam = nBufSize
  // (LPSTR)lParam = szStatus
  // return (UINT_PTR)cchRequiredSize

#ifdef EE_STRICT
inline UINT_PTR Editor_GetStatusA( HWND hwnd, LPCSTR szStatus, UINT_PTR nBufSize )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_STATUSA, (WPARAM)nBufSize, (LPARAM)(LPCSTR)(szStatus) );
}
#else
#define Editor_GetStatusA( hwnd, szStatus, nBufSize ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_STATUSA, (WPARAM)nBufSize, (LPARAM)(LPCSTR)(szStatus) )
#endif

#define EE_GET_STATUSW          (EE_FIRST+62)
  // (UINT_PTR)wParam = nBufSize
  // (LPWSTR)lParam = szStatus
  // return (UINT_PTR)cchRequiredSize

#ifdef EE_STRICT
inline UINT_PTR Editor_GetStatusW( HWND hwnd, LPCWSTR szStatus, UINT_PTR nBufSize )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_STATUSW, (WPARAM)nBufSize, (LPARAM)(LPCWSTR)(szStatus) );
}
#else
#define Editor_GetStatusW( hwnd, szStatus, nBufSize ) \
    (UINT_PTR)SNDMSG( (hwnd), EE_GET_STATUSW, (WPARAM)nBufSize, (LPARAM)(LPCWSTR)(szStatus) )
#endif

#define EE_INSERT_FILEA         (EE_FIRST+63)
  // (LOAD_FILE_INFO_EX*)wParam = plfi
  // (LPCSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_InsertFileA( HWND hwnd, LOAD_FILE_INFO_EX* plfi, LPCSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_INSERT_FILEA, (WPARAM)plfi, (LPARAM)(LPCSTR)(szFileName) );
}
#else
#define Editor_InsertFileA( hwnd, plfi, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_INSERT_FILEA, (WPARAM)(LOAD_FILE_INFO_EX*)plfi, (LPARAM)(LPCSTR)(szFileName) )
#endif

#define EE_INSERT_FILEW         (EE_FIRST+64)
  // (LOAD_FILE_INFO_EX*)wParam = plfi
  // (LPCWSTR)lParam = szFileName
  // returns non-zero if success, 0 if failed

#ifdef EE_STRICT
inline BOOL Editor_InsertFileW( HWND hwnd, LOAD_FILE_INFO_EX* plfi, LPCWSTR szFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_INSERT_FILEW, (WPARAM)(LOAD_FILE_INFO_EX*)plfi, (LPARAM)(LPCWSTR)(szFileName) );
}
#else
#define Editor_InsertFileW( hwnd, plfi, szFileName ) \
    (BOOL)SNDMSG( (hwnd), EE_INSERT_FILEW, (WPARAM)plfi, (LPARAM)(LPCWSTR)(szFileName) )
#endif

#define EE_FIND_IN_FILESA       (EE_FIRST+65)
  // wParam = 0
  // (GREP_INFOA*)lParam = pGrepInfo

#ifdef EE_STRICT
inline BOOL Editor_FindInFilesA( HWND hwnd, GREP_INFOA* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_FIND_IN_FILESA, (WPARAM)0, (LPARAM)(GREP_INFOA*)pGrepInfo );
}
#else
#define Editor_FindInFilesA( hwnd, pGrepInfo ) \
    (BOOL)SNDMSG( (hwnd), EE_FIND_IN_FILESA, (WPARAM)0, (LPARAM)pGrepInfo )
#endif

#define EE_FIND_IN_FILESW       (EE_FIRST+66)
  // wParam = 0
  // (GREP_INFOW*)lParam = pGrepInfo

#ifdef EE_STRICT
inline BOOL Editor_FindInFilesW( HWND hwnd, GREP_INFOW* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_FIND_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo );
}

inline BOOL Editor_FindInFiles( HWND hwnd, GREP_INFO_EX* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( (hwnd), EE_FIND_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo );
}
#else
#define Editor_FindInFilesW( hwnd, pGrepInfo ) \
    (BOOL)SNDMSG( (hwnd), EE_FIND_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo )
#endif

#define EE_REPLACE_IN_FILESA        (EE_FIRST+67)
  // wParam = 0
  // (GREP_INFOA*)lParam = pGrepInfo

#ifdef EE_STRICT
inline BOOL Editor_ReplaceInFilesA( HWND hwnd, GREP_INFOA* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_REPLACE_IN_FILESA, (WPARAM)0, (LPARAM)pGrepInfo );
}
#else
#define Editor_ReplaceInFilesA( hwnd, pGrepInfo ) \
    (BOOL)SNDMSG( (hwnd), EE_REPLACE_IN_FILESA, (WPARAM)0, (LPARAM)(GREP_INFOA*)pGrepInfo )
#endif

#define EE_REPLACE_IN_FILESW        (EE_FIRST+68)
  // wParam = 0
  // (GREP_INFOW*)lParam = pGrepInfo

#ifdef EE_STRICT
inline BOOL Editor_ReplaceInFilesW( HWND hwnd, GREP_INFOW* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( hwnd, EE_REPLACE_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo );
}

inline BOOL Editor_ReplaceInFiles( HWND hwnd, GREP_INFO_EX* pGrepInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( hwnd, EE_REPLACE_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo );
}
#else
#define Editor_ReplaceInFilesW( hwnd, pGrepInfo ) \
    (BOOL)SNDMSG( (hwnd), EE_REPLACE_IN_FILESW, (WPARAM)0, (LPARAM)pGrepInfo )
#endif

#define EE_GET_ANCHOR_POS           (EE_FIRST+69)
  // (int)wParam = nLogical
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline void Editor_GetAnchorPos( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_GET_ANCHOR_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_GetAnchorPos( hwnd, nLogical, pptPos ) \
    (void)SNDMSG( (hwnd), EE_GET_ANCHOR_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_SET_ANCHOR_POS           (EE_FIRST+70)
  // (int)wParam = nLogical
  // (POINT_PTR*)lParam = pptPos

#ifdef EE_STRICT
inline HRESULT Editor_SetAnchorPos( HWND hwnd, int nLogical, POINT_PTR* pptPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (HRESULT)SNDMSG( (hwnd), EE_SET_ANCHOR_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) );
}
#else
#define Editor_SetAnchorPos( hwnd, nLogical, pptPos ) \
    (HRESULT)SNDMSG( (hwnd), EE_SET_ANCHOR_POS, (WPARAM)(int)(nLogical), (LPARAM)(POINT_PTR*)(pptPos) )
#endif

#define EE_GET_REDRAW               (EE_FIRST+71)

#ifdef EE_STRICT
inline BOOL Editor_GetRedraw( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_GET_REDRAW, (WPARAM)0, (LPARAM)0 );
}
#else
#define Editor_GetRedraw( hwnd ) \
    (BOOL)SNDMSG( (hwnd), EE_GET_REDRAW, (WPARAM)0, (LPARAM)0 )
#endif

#define EE_DO_IDLE                  (EE_FIRST+72)

#ifdef EE_STRICT
inline void Editor_DoIdle( HWND hwnd, BOOL bResetTab )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_DO_IDLE, (WPARAM)(bResetTab), (LPARAM)0 );
}
#else
#define Editor_DoIdle( hwnd, bResetTab ) \
    (void)SNDMSG( (hwnd), EE_DO_IDLE, (WPARAM)(bResetTab), (LPARAM)0 )
#endif

#define	EE_CUSTOM_BAR_OPEN			(EE_FIRST+73)
  // (CUSTOM_BAR_INFO*)lParam = pCustomBarInfo

#ifdef EE_STRICT
inline UINT Editor_CustomBarOpen( HWND hwnd, CUSTOM_BAR_INFO* pCustomBarInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT)SNDMSG( (hwnd), EE_CUSTOM_BAR_OPEN, 0, (LPARAM)pCustomBarInfo );
}
#else
#endif

#define	EE_CUSTOM_BAR_CLOSE			(EE_FIRST+74)
  // (int)wParam = nCustomBarID

#ifdef EE_STRICT
inline BOOL Editor_CustomBarClose( HWND hwnd, UINT nCustomBarID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_CUSTOM_BAR_CLOSE, (WPARAM)nCustomBarID, 0 );
}
#else
#endif

#define EE_MATCH_REGEX				(EE_FIRST+75)

#ifdef EE_STRICT
inline int Editor_MatchRegex( HWND hwnd, MATCH_REGEX_INFO* pMatchRegexInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_MATCH_REGEX, (WPARAM)0, (LPARAM)pMatchRegexInfo );
}

inline int Editor_MatchRegex( HWND hwnd, MATCH_REGEX_INFO_EX* pMatchRegexInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_MATCH_REGEX, (WPARAM)0, (LPARAM)pMatchRegexInfo );
}
#else
#define Editor_MatchRegex( hwnd, pMatchRegexInfo ) \
	(int)SNDMSG( (hwnd), EE_MATCH_REGEX, (WPARAM)0, (LPARAM)pMatchRegexInfo )
#endif

#define EE_FIND_REGEX				(EE_FIRST+76)

#ifdef EE_STRICT
inline BOOL Editor_FindRegex( HWND hwnd, FIND_REGEX_INFO* pFindRegexInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( (hwnd), EE_FIND_REGEX, (WPARAM)0, (LPARAM)pFindRegexInfo );
}

inline BOOL Editor_FindRegex( HWND hwnd, FIND_REGEX_INFO_EX* pFindRegexInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( (hwnd), EE_FIND_REGEX, (WPARAM)0, (LPARAM)pFindRegexInfo );
}
#else
#define Editor_FindRegex( hwnd, pFindRegexInfo ) \
	(BOOL)SNDMSG( (hwnd), EE_FIND_REGEX, (WPARAM)0, (LPARAM)pFindRegexInfo )
#endif

#define EE_GET_OUTLINE_LEVEL		(EE_FIRST+77)
// (INT_PTR)wParam = nLogicalLine
// return nLevel

inline int Editor_GetOutlineLevel( HWND hwnd, INT_PTR nLogicalLine )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_GET_OUTLINE_LEVEL, (WPARAM)nLogicalLine, (LPARAM)0 );
}

#define EE_SET_OUTLINE_LEVEL		(EE_FIRST+78)
// (INT_PTR)wParam = nLogicalLine
// (int)lParam = nLevel
// return nOldLevel

inline int Editor_SetOutlineLevel( HWND hwnd, INT_PTR nLogicalLine, int nLevel )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_SET_OUTLINE_LEVEL, (WPARAM)nLogicalLine, (LPARAM)nLevel );
}

#define EE_SHOW_OUTLINE		(EE_FIRST+79)
// (UINT)wParam = nFlags
// return lResult

inline void Editor_ShowOutline( HWND hwnd, WPARAM nFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	SNDMSG( (hwnd), EE_SHOW_OUTLINE, (WPARAM)nFlags, (LPARAM)0 );
}

#define SHOW_OUTLINE_SHOW	1
#define SHOW_OUTLINE_HIDE	0


#define EE_ENUM_CONFIG		(EE_FIRST+80)
// (size_t)wParam = cchBuf
// (LPWSTR)lParam = pBuf
// return nSize

inline size_t Editor_EnumConfig( HWND hwnd, LPWSTR pBuf, size_t cchBuf )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (size_t)SNDMSG( (hwnd), EE_ENUM_CONFIG, (WPARAM)cchBuf, (LPARAM)pBuf );
}

#define	EE_TOOLBAR_OPEN			(EE_FIRST+81)
  // (TOOLBAR_INFO*)lParam = pToolbarInfo

inline UINT Editor_ToolbarOpen( HWND hwnd, TOOLBAR_INFO* pToolbarInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT)SNDMSG( (hwnd), EE_TOOLBAR_OPEN, 0, (LPARAM)pToolbarInfo );
}

#define	EE_TOOLBAR_CLOSE			(EE_FIRST+82)
  // (UINT)wParam = nToolbarID

inline BOOL Editor_ToolbarClose( HWND hwnd, UINT nCustomRebarID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_TOOLBAR_CLOSE, (WPARAM)nCustomRebarID, 0 );
}

#define	EE_TOOLBAR_SHOW			(EE_FIRST+83)
  // (UINT)wParam = nToolbarID
  // (BOOL)lParam = bVisible

inline BOOL Editor_ToolbarShow( HWND hwnd, UINT nCustomRebarID, BOOL bVisible )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (BOOL)SNDMSG( (hwnd), EE_TOOLBAR_SHOW, (WPARAM)nCustomRebarID, (LPARAM)bVisible );
}

#define EE_HELP							(EE_FIRST+84)
  // (UINT)wParam = nFlag (must be 0)
  // (LPCTSTR)lParam = szPageURL

inline void Editor_Help( HWND hwnd, LPCTSTR szPageURL )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    SNDMSG( (hwnd), EE_HELP, 0, (LPARAM)szPageURL );
}

#define EE_REG_SET_VALUE				(EE_FIRST+85)
  // (REG_SET_VALUE_INFO*)lParam = pRegSetValueInfo;

inline LONG Editor_RegSetValue( HWND hwnd, DWORD dwKey, LPCWSTR pszConfig, LPCWSTR pszValue, DWORD dwType, const BYTE* lpData, DWORD cbData, DWORD dwFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	REG_SET_VALUE_INFO info = { 0 };
	info.cbSize = sizeof( info );
	info.dwKey = dwKey;
	info.pszConfig = pszConfig;
	info.pszValue = pszValue;
	info.dwType = dwType;
	info.lpData = lpData;
	info.cbData = cbData;
	info.dwFlags = dwFlags;
    return (LONG)SNDMSG( (hwnd), EE_REG_SET_VALUE, 0, (LPARAM)&info );
}

#define EE_REG_QUERY_VALUE				(EE_FIRST+86)
  // (REG_QUERY_VALUE_INFO*)lParam = pRegQueryValueInfo;

inline LONG Editor_RegQueryValue( HWND hwnd, DWORD dwKey, LPCWSTR pszConfig, LPCWSTR pszValue, DWORD dwType, BYTE* lpData, DWORD* lpcbData, DWORD dwFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	REG_QUERY_VALUE_INFO info = { 0 };
	info.cbSize = sizeof( info );
	info.dwKey = dwKey;
	info.pszConfig = pszConfig;
	info.pszValue = pszValue;
	info.dwType = dwType;
	info.lpData = lpData;
	info.lpcbData = lpcbData;
	info.dwFlags = dwFlags;
    return (LONG)SNDMSG( (hwnd), EE_REG_QUERY_VALUE, 0, (LPARAM)&info );
}

#define EE_QUERY_STRING					(EE_FIRST+87)
  // (UINT)wParam = nCmdID, (LPWSTR)lParam = psz  (buffer must be MAX_PATH)
  // returns (BOOL)bValidCmd

inline BOOL Editor_QueryString( HWND hwnd, UINT nCmdID, LPWSTR psz, BOOL bShortTitle = FALSE )
{
    _ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( hwnd, EE_QUERY_STRING, (WPARAM)MAKEWPARAM( nCmdID, bShortTitle ), (LPARAM)psz );
}

#define EE_KEYBOARD_PROP				(EE_FIRST+88)
  // (UINT)wParam = nCmdID, (LPCWSTR)lParam = pszConfigName
  // returns (BOOL)bResult

inline BOOL Editor_KeyboardProp( HWND hwnd, UINT nCmdID, LPCWSTR pszConfigName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( hwnd, EE_KEYBOARD_PROP, (WPARAM)nCmdID, (LPARAM)pszConfigName );
}

#define EE_GET_ACCEL_ARRAY				(EE_FIRST+89)
  // (UINT)wParam = nBufSize (size of buffer in ACCEL)
  // (ACCEL*)lParam = pAccel

inline UINT Editor_GetAccelArray( HWND hwnd, ACCEL* pAccel, UINT nBufSize )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (UINT)SNDMSG( hwnd, EE_GET_ACCEL_ARRAY, (WPARAM)nBufSize, (LPARAM)pAccel );
}

#define EE_OUTPUT_STRING				(EE_FIRST+90)
  // (UINT)wParam = flags
  // (LPCWSTR)lParam = pszString

inline BOOL Editor_OutputString( HWND hwnd, LPCWSTR pszString, UINT flags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( hwnd, EE_OUTPUT_STRING, (WPARAM)flags, (LPARAM)pszString );
}

#define EE_OUTPUT_DIR					(EE_FIRST+91)
  // (LPCWSTR)lParam = pszCurrDir

inline BOOL Editor_OutputDir( HWND hwnd, LPCWSTR pszCurrDir )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (BOOL)SNDMSG( hwnd, EE_OUTPUT_DIR, (WPARAM)0, (LPARAM)pszCurrDir );
}

#define EE_ENUM_HIGHLIGHT				(EE_FIRST+92)
  // (LPWSTR)pBuf
  // (size_t)cchBuf

inline size_t Editor_EnumHighlight( HWND hwnd, LPWSTR pBuf, size_t cchBuf )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (size_t)SNDMSG( (hwnd), EE_ENUM_HIGHLIGHT, (WPARAM)cchBuf, (LPARAM)pBuf );
}

#define EE_OUTPUT_PROCESS				(EE_FIRST+93)
  // wParam = 0
  // (PROCESS_INFO*)lParam = pProcessInfo
  
inline BOOL Editor_OutputProcess( HWND hwnd, LPCWSTR pszAppName, LPCWSTR pszCmdLine, LPCWSTR pszDir, UINT nFlags, UINT nCP )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	PROCESS_INFO pi = { 0 };
	pi.cbSize = sizeof( pi );
	pi.pszAppName = pszAppName;
	pi.pszCmdLine = pszCmdLine;
	pi.pszDir = pszDir;
	pi.nFlags = nFlags;
	pi.nCP = nCP;
	return (BOOL)SNDMSG( hwnd, EE_OUTPUT_PROCESS, (WPARAM)0, (LPARAM)&pi );
}

#define EE_GET_DROPPED_FILE				(EE_FIRST+94)
  // (int)wParam = nIndex
  // (LPWSTR)lParam = pszBuf

inline UINT Editor_GetDroppedFile( HWND hwnd, int nIndex, LPWSTR pszBuf )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (UINT)SNDMSG( hwnd, EE_GET_DROPPED_FILE, (WPARAM)nIndex, (LPARAM)pszBuf );
}

typedef struct _RUN_MACRO_INFO {
	size_t  cbSize;
	LPCWSTR pszMacroFile;
	LPCWSTR pszText;
	UINT	nFlags;
	int     nDefMacroLang;
	POINT_PTR ptOrgPos;
	POINT_PTR ptCodePos;
	POINT_PTR ptErrorPos;
	HGLOBAL hstrResult;
} RUN_MACRO_INFO;


#define S_EDIT_TEMP	 ((HRESULT)2)
#define MACRO_LANG_JSCRIPT		0
#define MACRO_LANG_VBSCRIPT		1
#define MACRO_LANG_CHAKRA		2
#define MACRO_LANG_UNKNOWN		0x000000ff

#define EE_RUN_MACRO					(EE_FIRST+95)
  // (RUN_MACRO_INFO*)lParam = pRunMacroInfo
  // retusn  S_OK        (success)
  //         S_FALSE     (macro error like syntax error)
  //         S_EDIT_TEMP (macro error but could not open temporary file when trying to edit)
  //         E_FAIL      (error)

inline HRESULT Editor_RunMacro( HWND hwnd, UINT nFlags, UINT nDefMacroLang, LPCWSTR pszMacroFile, LPCWSTR pszText, POINT_PTR* pptOrgPos, POINT_PTR* pptCodePos, POINT_PTR* pptErrorPos, HGLOBAL* phstrResult )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	RUN_MACRO_INFO rmi = { 0 };
	rmi.cbSize = sizeof( rmi );
	rmi.pszMacroFile = pszMacroFile;
	rmi.pszText = pszText;
	rmi.nFlags = nFlags;
	rmi.nDefMacroLang = nDefMacroLang;
	rmi.ptErrorPos.x = rmi.ptErrorPos.y = -1;
	if( pptOrgPos ) {
		rmi.ptOrgPos.x = pptOrgPos->x;
		rmi.ptOrgPos.y = pptOrgPos->y;
	}
	if( pptCodePos ) {
		rmi.ptCodePos.x = pptCodePos->x;
		rmi.ptCodePos.y = pptCodePos->y;
	}
	if( phstrResult ){
		rmi.hstrResult = *phstrResult;
	}
	HRESULT hr = (HRESULT)SNDMSG( hwnd, EE_RUN_MACRO, 0, (LPARAM)&rmi );
	if( pptErrorPos ){
		pptErrorPos->x = rmi.ptErrorPos.x;
		pptErrorPos->y = rmi.ptErrorPos.y;
	}
	if( phstrResult ){
		*phstrResult = rmi.hstrResult;
	}
	return hr;
}


//inline UINT Editor_RunMacro( HWND hwnd, UINT nFlags, LPCWSTR pszMacroFile )
//{
//	return (UINT)SNDMSG( hwnd, EE_RUN_MACRO, (WPARAM)nFlags, (LPARAM)pszMacroFile );
//}

#define TEMP_INFO_OPEN			0
#define TEMP_INFO_CLOSED		1
#define TEMP_INFO_CLOSE			1
#define TEMP_INFO_SAVE			2
#define TEMP_INFO_QUIT			4

typedef struct _TEMP_INFO {
	size_t		cbSize;
	LPCWSTR		pszTempText;
	LPCWSTR		pszTitle;
	LPCWSTR		pszIconPath;
	LPCWSTR		pszConfig;
	POINT_PTR	ptInitialCaret;
	UINT		nID;
	UINT		nEncoding;
	UINT		nFlags;
} TEMP_INFO;


#define EE_EDIT_TEMP					(EE_FIRST+96)

inline UINT Editor_EditTemp( HWND hwnd, LPCWSTR pszTempText, LPCWSTR pszTitle, LPCWSTR pszIconPath, LPCWSTR pszConfig, UINT nEncoding, POINT_PTR* pptInitialCaret = NULL, UINT nFlags = 0 )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	TEMP_INFO ti = { 0 };
	ti.cbSize = sizeof( ti );
	ti.pszTempText = pszTempText;
	ti.pszTitle = pszTitle;
	ti.pszIconPath = pszIconPath;
	ti.pszConfig = pszConfig;
	if( pptInitialCaret ){
		ti.ptInitialCaret = *pptInitialCaret;
	}
	else {
		ti.ptInitialCaret.x = ti.ptInitialCaret.y = -1;
	}
	ti.nEncoding = nEncoding;
	ti.nFlags = nFlags;
	return (UINT)SNDMSG( hwnd, EE_EDIT_TEMP, (WPARAM)0, (LPARAM)&ti );
}

inline UINT Editor_ActivateTemp( HWND hwnd, UINT nEditID, POINT_PTR* pptInitialCaret = NULL )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	TEMP_INFO ti = { 0 };
	ti.cbSize = sizeof( ti );
	ti.nID = nEditID;
	if( pptInitialCaret ){
		ti.ptInitialCaret = *pptInitialCaret;
	}
	else {
		ti.ptInitialCaret.x = ti.ptInitialCaret.y = -1;
	}
	return (UINT)SNDMSG( hwnd, EE_EDIT_TEMP, (WPARAM)0, (LPARAM)&ti );
}

inline UINT Editor_SaveTemp( HWND hwnd, UINT nEditID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	TEMP_INFO ti = { 0 };
	ti.cbSize = sizeof( ti );
	ti.nID = nEditID;
	ti.nFlags = TEMP_INFO_SAVE;
	return (UINT)SNDMSG( hwnd, EE_EDIT_TEMP, (WPARAM)0, (LPARAM)&ti );
}

inline UINT Editor_CloseTemp( HWND hwnd, UINT nEditID )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	TEMP_INFO ti = { 0 };
	ti.cbSize = sizeof( ti );
	ti.nID = nEditID;
	ti.nFlags = TEMP_INFO_CLOSE;
	return (UINT)SNDMSG( hwnd, EE_EDIT_TEMP, (WPARAM)0, (LPARAM)&ti );
}

typedef struct _CLIP_INFO {
	size_t	cbSize;
	LPWSTR	pszBuf;
	UINT	cchBuf;
	UINT	iPos;
	UINT	nAction;
	UINT	nFlags;
} CLIP_INFO;

#define CI_GET_CLIP		0
#define CI_INSERT_CLIP	1
#define CI_REMOVE_CLIP	2
#define CI_GET_CLIP_POS	3
#define CI_SET_CLIP_POS	4
#define CI_ROTATE_CLIP	5

#define CI_FLAG_NO_UPDATE_REAL_CLIP	0x00001000

#define MAX_CLIP_LEN	0x00020000

#define EE_CLIP_HISTORY			(EE_FIRST+97)

inline UINT Editor_GetClip( HWND hwnd, LPWSTR pszBuf, UINT cchBuf, UINT iPos, UINT* pnFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_GET_CLIP;
	ci.pszBuf = pszBuf;
	ci.cchBuf = cchBuf;
	ci.iPos = iPos;
	ci.nFlags = *pnFlags;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	*pnFlags = ci.nFlags;
	return nResult;
}

inline UINT Editor_InsertClip( HWND hwnd, LPCWSTR pszText, UINT iPos, UINT nFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_INSERT_CLIP;
	ci.pszBuf = (LPWSTR)pszText;
	ci.iPos = iPos;
	ci.nFlags = nFlags;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	return nResult;
}

inline UINT Editor_RemoveClip( HWND hwnd, UINT iPos, UINT nFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_REMOVE_CLIP;
	ci.iPos = iPos;
	ci.nFlags = nFlags;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	return nResult;
}

inline int Editor_GetClipPos( HWND hwnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_GET_CLIP_POS;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	return (int)nResult;
}

inline UINT Editor_SetClipPos( HWND hwnd, int iPos )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_SET_CLIP_POS;
	ci.iPos = (UINT)iPos;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	return nResult;
}

inline UINT Editor_RotateClip( HWND hwnd, int iDirection )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CLIP_INFO ci = { 0 };
	ci.cbSize = sizeof( ci );
	ci.nAction = CI_ROTATE_CLIP;
	ci.iPos = (UINT)iDirection;
	UINT nResult = (UINT)SNDMSG( hwnd, EE_CLIP_HISTORY, (WPARAM)0, (LPARAM)&ci );
	return nResult;
}


#define EE_GET_OUTPUT_STRING		(EE_FIRST+98)

inline UINT Editor_GetOutputString( HWND hwnd, UINT cchBuf, LPWSTR pBuf )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	UINT nResult = (UINT)SNDMSG( hwnd, EE_GET_OUTPUT_STRING, (WPARAM)cchBuf, (LPARAM)pBuf );
	return nResult;
}


#define ATTR_NONE			0x00
#define ATTR_COMMENT		0x10
#define ATTR_DOUBLE_QUOTE	0x20
#define ATTR_SINGLE_QUOTE	0x40
#define ATTR_TAG			0x80

#define AI_NEED_CONFIG_SCOPE	0x01
#define AI_NEED_CONFIG_DOC		0x02
#define AI_NEED_ATTR_SUB		0x04
#define AI_NEED_ALL				0x07


typedef struct _ATTR_INFO {
	size_t	cbSize;        // in
	POINT_PTR ptLogical;  // in
	UINT	nFlags;        // in
	UINT    nAttr;         // out
	WCHAR   szConfigScope[MAX_CONFIG_NAME];  // out
	WCHAR   szConfigDoc[MAX_CONFIG_NAME];    // out
} ATTR_INFO;


#define EE_GET_ATTR					(EE_FIRST+99)

inline BOOL Editor_GetAttr( HWND hwnd, ATTR_INFO* pAI )
{
	return (BOOL)SNDMSG( hwnd, EE_GET_ATTR, 0, (LPARAM)pAI );
}

#define EE_GET_WORD					(EE_FIRST+100)
  // (UINT_PTR)wParam = nBufferSize, (LPWSTR)lParam = szBuffer
  // returns (UINT_PTR)nRequiredBufferSize

inline UINT_PTR Editor_GetWord( HWND hwnd, UINT_PTR nBufferSize, LPWSTR szBuffer )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_WORD, (WPARAM)nBufferSize, (LPARAM)szBuffer );
}

typedef struct _SEL_INFO {
	POINT_PTR	ptStart;
	POINT_PTR	ptEnd;
} SEL_INFO;

#define EE_GET_MULTI_SEL					(EE_FIRST+101)
  // (UINT_PTR)wParam = nBufferSize, (LPWSTR)lParam = szBuffer
  // returns (UINT_PTR)nRequiredBufferSize

inline UINT_PTR Editor_GetMultiSel( HWND hwnd, UINT_PTR iSel, SEL_INFO* pSelInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( hwnd, EE_GET_MULTI_SEL, (WPARAM)iSel, (LPARAM)pSelInfo );
}

typedef struct _OUTLINE_ARRAY_INFO
{
	int nVersion;  // must be 1
	UINT nFlags;   // must be 0
	INT_PTR nStartLine;
	INT_PTR nCount;
	BYTE* pLevelData;
} OUTLINE_ARRAY_INFO;

#define EE_SET_OUTLINE_ARRAY				(EE_FIRST+102)
  // wParam = 0
  // (OUTLINE_ARRAY_INFO*)lParam = pOutlineArrayInfo
  // return bSuccess

inline BOOL Editor_SetOutlineArray( HWND hwnd, INT_PTR nStartLine, INT_PTR nCount, BYTE* pLevelData )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	OUTLINE_ARRAY_INFO info;
	info.nStartLine = nStartLine;
	info.nCount = nCount;
	info.pLevelData = pLevelData;
	return (BOOL)SNDMSG( (hwnd), EE_SET_OUTLINE_ARRAY, 0, (LPARAM)&info );
}

typedef struct _GET_COLOR_INFO
{
	UINT cbSize;
	BOOL bFind;
	UINT nIndex;
	COLORREF clrText;
	COLORREF clrBack;
	int      nAttr;
} GET_COLOR_INFO;

#define EE_GET_COLOR						(EE_FIRST+103)
  // wParam = 0
  // (GET_COLOR_INFO*)lParam = pGetColorInfo;
  // return bSuccess;

inline BOOL Editor_GetColor( HWND hwnd, BOOL bFind, UINT nIndex, COLORREF* pclrText, COLORREF* pclrBack, int* pnAttr )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	GET_COLOR_INFO info;
	info.cbSize = sizeof( info );
	info.bFind = bFind;
	info.nIndex = nIndex;
	BOOL bSuccess = (BOOL)SNDMSG( (hwnd), EE_GET_COLOR, 0, (LPARAM)&info );
	if( bSuccess ){
		if( pclrText ){
			*pclrText = info.clrText;
		}
		if( pclrBack ){
			*pclrBack = info.clrBack;
		}
		if( pnAttr ){
			*pnAttr = info.nAttr;
		}
	}
	return bSuccess;
}

#define CELL_INCLUDE_NONE					0
#define CELL_INCLUDE_QUOTES					1
#define CELL_INCLUDE_QUOTES_AND_DELIMITER	2
#define CELL_INCLUDE_LINES					3
#define CELL_INCLUDE_MASK					3
#define CELL_ABSOLUTE_INDEX					8
#define CELL_DONT_CHECK_DELIMITER			0x0010
#define USE_HGLOBAL							0x0020

#define SORT_DESCEND							0x00000000
#define SORT_ASCEND								0x80000000
#define SORT_TEXT								0x00000000
#define SORT_NUM								0x40000000
#define SORT_IGNORE_PREFIX						0x20000000
#define SORT_LENGTH_VIEW						0x10000000
#define SORT_DELETE_DUPLICATE					0x08000000
#define SORT_ENABLED							0x04000000
#define SORT_STABLE								0x02000000
#define SORT_BINARY_COMPARISON					0x01000000
#define SORT_UNQUOTE_CELLS						0x00800000
#define SORT_LENGTH								0x00400000
#define SORT_OCCURRENCE							0x00200000
#define SORT_WORDS								0x00100000
#define SORT_DATE								0x00080000
#define SORT_SELECTION_ONLY						0x00040000
#define SORT_RANDOM								0x00008000
#define SORT_REVERSE							0x00006000
#define SORT_IPV4								0x00004000
#define SORT_IPV6								0x00002000
#define SORT_GROUP_IDENTICAL					0x00000400
#define SORT_INSPECT_NOT_SEL_ONLY				0x00000200
#define MANAGE_DUPLICATES_ADJACENT_ONLY			0x00020000
#define MANAGE_DUPLICATES_IGNORE_EMPTY_LINES	0x00010000
#define MANAGE_DUPLICATES_INCLUDE_ALL			0x00008000
#define MANAGE_DUPLICATES_LARGE_TEST			0x00004000
#define MANAGE_DUPLICATES_IGNORE_EMPTY_CELLS	0x00002000
#define MANAGE_DUPLICATES_SELECTION_ONLY		SORT_SELECTION_ONLY
#define MANAGE_DUPLIDATES_INSPECT_SEL_ONLY		0x00000100
#define MANAGE_DUPLICATES_BOOKMARK				0x00200000
#define MANAGE_DUPLICATES_IGNORE_CASE			NORM_IGNORECASE   // 1

#define SORT_MASK				(NORM_IGNORECASE|NORM_IGNOREKANATYPE|NORM_IGNORENONSPACE|NORM_IGNORESYMBOLS|NORM_IGNOREWIDTH|SORT_STRINGSORT|SORT_DIGITSASNUMBERS)   // 0x0003100f
#define SORT_MASK_ALL			(SORT_MASK | SORT_IGNORE_PREFIX | SORT_LENGTH_VIEW | SORT_STABLE | SORT_BINARY_COMPARISON | SORT_UNQUOTE_CELLS | SORT_INSPECT_NOT_SEL_ONLY | SORT_GROUP_IDENTICAL)
#define MANAGE_DUPLICATES_MASK	(MANAGE_DUPLICATES_IGNORE_EMPTY_LINES | MANAGE_DUPLICATES_BOOKMARK | MANAGE_DUPLICATES_ADJACENT_ONLY | MANAGE_DUPLICATES_INCLUDE_ALL | MANAGE_DUPLICATES_IGNORE_CASE | MANAGE_DUPLICATES_LARGE_TEST | MANAGE_DUPLICATES_IGNORE_EMPTY_CELLS | MANAGE_DUPLIDATES_INSPECT_SEL_ONLY)
#define DEF_SORT_OPTIONS		(SORT_IGNORE_PREFIX)
#define SORT_SPLIT_COLUMN_MASK  (SORT_MASK | SORT_IGNORE_PREFIX | SORT_LENGTH_VIEW | SORT_STABLE | SORT_BINARY_COMPARISON | SORT_GROUP_IDENTICAL | SORT_DELETE_DUPLICATE | SORT_ASCEND | SORT_ASCEND | SORT_LENGTH | SORT_OCCURRENCE | SORT_WORDS | SORT_DATE | SORT_RANDOM | SORT_REVERSE | SORT_IPV4 | SORT_IPV6)

typedef struct _GET_CELL_INFO {
    UINT_PTR	cch;		// in
    UINT		flags;		// in
    UINT_PTR	yLine;		// in
	int			iColumn;	// in
} GET_CELL_INFO;


#define EE_GET_CELL						(EE_FIRST+104)
  // (GET_CELL_INFO*)wParam = pGetCellInfo, (LPWSTR)lParam = szString
  // returns (UINT_PTR)nRequiredBufferSize

inline UINT_PTR Editor_GetCell( HWND hwnd, GET_CELL_INFO* pGetCellInfo, LPWSTR szString )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
    return (UINT_PTR)SNDMSG( (hwnd), EE_GET_CELL, (WPARAM)(GET_CELL_INFO*)(pGetCellInfo), (LPARAM)(LPWSTR)(szString) );
}

typedef struct _FILTER_INFO {
    UINT		cbSize;    // in
    UINT		flags;		// in
	int			iColumn;	// in
	LPCWSTR		pszFilter;  // in
	INT_PTR		xBegin;		// in
	INT_PTR		xEnd;		// in
} FILTER_INFO;

typedef struct _FILTER_INFO_EX {
	UINT		cbSize;
	UINT64      flags;
	int			iColumn;
	LPCWSTR		pszFilter;
	INT_PTR		xBegin;
	INT_PTR		xEnd;
	UINT		cchFilter;
} FILTER_INFO_EX;

#define EE_FILTER                (EE_FIRST+105)
  // (FILTER_INFO_EX*)wParam = pFilterInfo
  // returns (int)nCount

inline int Editor_Filter( HWND hwnd, LPCWSTR szFilter, int iColumn, UINT64 nFlags, INT_PTR xBegin, INT_PTR xEnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	FILTER_INFO_EX fi = { 0 };
	fi.cbSize = sizeof( fi );
	fi.flags = nFlags;
	fi.iColumn = iColumn;
	fi.pszFilter = szFilter;
	fi.xBegin = xBegin;
	fi.xEnd = xEnd;
    return (int)SNDMSG( (hwnd), EE_FILTER, (WPARAM)&fi, 0 );
}

#define JOIN_FLAG_UNIQUE_KEY_1		0x0001
#define JOIN_FLAG_UNIQUE_KEY_2		0x0002
#define JOIN_FLAG_INCLUDE_ALL_1		0x0004
#define JOIN_FLAG_INCLUDE_ALL_2		0x0008
#define JOIN_FLAG_MATCH_CASE		0x0010
#define JOIN_FLAG_SIMPLE_JOIN		0x0020
#define JOIN_FLAG_IGNORE_HEADINGS_1	0x0040
#define JOIN_FLAG_IGNORE_HEADINGS_2	0x0080
#define JOIN_FLAG_MASK				0x00ff
#define DEF_JOIN_FLAG				(JOIN_FLAG_IGNORE_HEADINGS_1 | JOIN_FLAG_IGNORE_HEADINGS_2)


typedef struct _JOIN_INFO {
	UINT		cbSize;
	UINT		flags;
	LPCWSTR		pszDocument1;
	LPCWSTR		pszDocument2;
	LPCWSTR		pszColumn1;
	LPCWSTR		pszColumn2;
	LPCWSTR		pszSelect;
	UINT		iDocument3;
} JOIN_INFO;


#define EE_JOIN					 (EE_FIRST+106)
  // (JOIN_INFO*)wParam = pJoinInfo
  // returns (int)nCount

inline int Editor_Join( HWND hwnd, UINT nFlags, LPCWSTR pszDocument1, LPCWSTR pszColumn1, LPCWSTR pszDocument2, LPCWSTR pszColumn2, LPCWSTR pszSelect, int* piDocument3 )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	JOIN_INFO ji;
	ji.cbSize = sizeof( ji );
	ji.flags = nFlags;
	ji.pszDocument1 = pszDocument1;
	ji.pszDocument2 = pszDocument2;
	ji.pszColumn1 = pszColumn1;
	ji.pszColumn2 = pszColumn2;
	ji.pszSelect = pszSelect;
    int nResult = (int)SNDMSG( (hwnd), EE_JOIN, (WPARAM)&ji, 0 );
	if( nResult >= 0 && piDocument3 != NULL ) {
		*piDocument3 = ji.iDocument3;
	}
	return nResult;
}


#define PLUGIN_FLAG_EXEC_COMMAND	0
#define PLUGIN_FLAG_USER_MSG		1
#define PLUGIN_FLAG_QUERY_STATUS	2
#define PLUGIN_FLAG_ABSOLUTE_PATH	4

#define STATUS_ENABLED		2
#define STATUS_LATCHED		4

typedef struct _EXEC_PLUGIN_INFO {
	UINT	cbSize;
	LONG	 nFlags;
	LPCWSTR	 pszName;
	WPARAM   wParam;
	LPARAM   lParam;
	LONG_PTR nResult;
} EXEC_PLUGIN_INFO;

#define EE_EXEC_PLUGIN		(EE_FIRST+107)

inline HRESULT Editor_ExecPlugin( HWND hwnd, LPCWSTR pszName, LONG nFlags, WPARAM wParam, LPARAM lParam, LONG_PTR* pnResult )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	EXEC_PLUGIN_INFO epi;
	epi.cbSize = sizeof( epi );
	epi.nFlags = nFlags;
	epi.pszName = pszName;
	epi.wParam = wParam;
	epi.lParam = lParam;
	HRESULT hr = (HRESULT)SNDMSG( (hwnd), EE_EXEC_PLUGIN, (WPARAM)&epi, 0 );
	if( SUCCEEDED( hr ) && pnResult != NULL ) {
		*pnResult = epi.nResult;
	}
	return hr;
}

#define EE_FIND_REPLACE	(EE_FIRST+108)

typedef struct _FIND_REPLACE_INFO {
	UINT	cbSize;
	UINT64	 nFlags;
	LPCWSTR	 pszFind;
	LPCWSTR	 pszReplace;
	UINT64	 nCount;
	UINT64   nMatchedLines;
} FIND_REPLACE_INFO;

typedef struct _BATCH_INFO {
	UINT   cbSize;
	UINT   nBatchCount;  // number of FIND_REPLACE_INFO structures in lParam;
	UINT64 nBatchFlags;
	UINT64 nTotalCount;
} BATCH_INFO;

inline HRESULT Editor_FindReplace( HWND hwnd, UINT64 nFlags, LPCWSTR pszFind, LPCWSTR pszReplace, UINT64* pnCount, UINT64* pnMatchedLines )
{
	FIND_REPLACE_INFO fri = { 0 };
	fri.cbSize = sizeof( fri );
	fri.nFlags = nFlags;
	fri.pszFind = pszFind;
	fri.pszReplace = pszReplace;
	HRESULT hr = (HRESULT)SNDMSG( (hwnd), EE_FIND_REPLACE, 0, (LPARAM)&fri );
	if( SUCCEEDED( hr ) )  {
		if( pnCount )  *pnCount = fri.nCount;
		if( pnMatchedLines )  *pnMatchedLines = fri.nMatchedLines;
	}
	return hr;
}

inline HRESULT Editor_BatchFindReplace( HWND hwnd, FIND_REPLACE_INFO* pBatchArray, UINT nBatchCount, UINT64 nBatchFlags, UINT64* pnTotalCount )
{
	BATCH_INFO bi = { sizeof( BATCH_INFO ) };
	bi.nBatchCount = nBatchCount;
	bi.nBatchFlags = nBatchFlags;
	HRESULT hr = (HRESULT)SNDMSG( ( hwnd ), EE_FIND_REPLACE, (WPARAM)&bi, (LPARAM)pBatchArray );
	if( SUCCEEDED( hr ) ) {
		if( pnTotalCount )  *pnTotalCount = bi.nTotalCount;
	}
	return hr;
}

#define EE_GET_FILTER (EE_FIRST+109)

inline int Editor_GetFilter( HWND hwnd, int iFilter, LPWSTR pszFilter, UINT cchFilter, int* piColumn, DWORD64* pnFlags, INT_PTR* pxBegin, INT_PTR* pxEnd )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	FILTER_INFO_EX fi = { 0 };
	fi.cbSize = sizeof( fi );
	fi.pszFilter = pszFilter;
	fi.cchFilter = cchFilter;
	int nResult = (int)SNDMSG( hwnd, EE_GET_FILTER, (WPARAM)&fi, (LPARAM)iFilter );
	if( nResult > 0 && iFilter >= 0 ) {
		*pnFlags = fi.flags;
		*piColumn = fi.iColumn;
		*pxBegin = fi.xBegin;
		*pxEnd = fi.xEnd;
	}
	return nResult;
}

#define EE_MANAGE_DUPLICATES (EE_FIRST+110)

#define VER_MANAGE_DUPLICATES_INFO		1

typedef struct _MANAGE_DUPLICATES_INFO {
	UINT	nVer;
	UINT	nFlags;
	INT_PTR nFound;
	int 	nNumOfColumns;
	int*    anColumns;
} MANAGE_DUPLICATES_INFO;

inline HRESULT Editor_ManageDuplicates( HWND hwnd, UINT nFlags, int nNumOfColumns, int* anColumns, INT_PTR* pnFound )
{
	MANAGE_DUPLICATES_INFO mdi = { 0 };
	mdi.nVer = VER_MANAGE_DUPLICATES_INFO;
	mdi.nFlags = nFlags;
	mdi.nNumOfColumns = nNumOfColumns;
	mdi.anColumns = anColumns;
	HRESULT hr = (HRESULT)SNDMSG( (hwnd), EE_MANAGE_DUPLICATES, 0, (LPARAM)&mdi );
	if( SUCCEEDED( hr ) ) {
		if( pnFound )  *pnFound = mdi.nFound;
	}
	return hr;
}

#define EE_SORT (EE_FIRST+111)

#define VER_SORT_INFO		1

typedef struct _COLUMN_INFO {
	int		iCol;
	UINT	nFlags;
} COLUMN_INFO;

typedef struct _SORT_INFO {
	UINT	nVer;
	UINT	nFlags;
	LPCWSTR pszLocale;
	BOOL	bModified;
	int 	nNumOfColumns;
	COLUMN_INFO* anColumns;
} SORT_INFO;

inline HRESULT Editor_Sort( HWND hwnd, UINT nFlags, LPCWSTR pszLocale, int nNumOfColumns, COLUMN_INFO* anColumns, BOOL* pbModified )
{
	SORT_INFO si = { 0 };
	si.nVer = VER_SORT_INFO;
	si.nFlags = nFlags;
	si.pszLocale = pszLocale;
	si.nNumOfColumns = nNumOfColumns;
	si.anColumns = anColumns;
	HRESULT hr = (HRESULT)SNDMSG((hwnd), EE_SORT, 0, (LPARAM)&si);
	if (SUCCEEDED(hr)) {
		if (pbModified)  *pbModified = si.bModified;
	}
	return hr;
}

#define CELL_AUTO_QUOTE					0
#define CELL_DONT_QUOTE					1
#define CELL_ALWAYS_QUOTE				2

#define EE_SET_CELL		(EE_FIRST+112)
// (SET_CELL_INFO*)wParam = pCellInfo, (LPWSTR)lParam = szString
// 

inline HRESULT Editor_SetCell( HWND hwnd, GET_CELL_INFO* pCellInfo, LPCWSTR szString )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (HRESULT)SNDMSG( (hwnd), EE_SET_CELL, (WPARAM)(GET_CELL_INFO*)(pCellInfo), (LPARAM)(LPCWSTR)(szString) );
}

#define SET_COLUMN_INSERT			0x0010

typedef struct _COLUMN_STRUCT_V1 {
	UINT        cbSize;
	int         iColumn;
	UINT_PTR    yLineTop;
	UINT_PTR    yLines;
	LPWSTR		pBuf;
	UINT_PTR    cchBuf;
	LPCWSTR     pszDelimiter;
	UINT        flags;
} COLUMN_STRUCT_V1;

typedef struct _COLUMN_STRUCT {
	UINT        cbSize;
	int         iColumn;
	UINT_PTR    yLineTop;
	UINT_PTR    yLines;
	LPWSTR		pBuf;
	UINT_PTR    cchBuf;
	LPCWSTR     pszDelimiter;
	UINT        flags;
	HGLOBAL		hGlobalData;
} COLUMN_STRUCT;

#define EE_SET_COLUMN		(EE_FIRST+113)
// wParam = 0, (COLUMN_STRUCT*)lParam = pColumnStruct
// 

inline HRESULT Editor_SetColumn( HWND hwnd, COLUMN_STRUCT* pColumnStruct )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (HRESULT)SNDMSG( (hwnd), EE_SET_COLUMN, 0, (LPARAM)(COLUMN_STRUCT*)(pColumnStruct) );
}

#define EE_GET_COLUMN		(EE_FIRST+114)
// wParam = 0, (COLUMN_STRUCT*)lParam = pColumnStruct
// 

inline HRESULT Editor_GetColumn( HWND hwnd, COLUMN_STRUCT* pColumnStruct )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (HRESULT)SNDMSG( (hwnd), EE_GET_COLUMN, 0, (LPARAM)(COLUMN_STRUCT*)(pColumnStruct) );
}

#define SHOW_TIP_HIDE			0
#define SHOW_TIP_ACTIVE_STRING	1
#define SHOW_TIP_CURRENT_CARET	2
#define SHOW_TIP_CURRENT_MOUSE	3
#define SHOW_TIP_TYPE_MASK		7

typedef struct _TIP_INFO {
	UINT		cbSize;
	LPCWSTR		pszTip;
	POINT_PTR	ptCaret;
	POINT		ptDev;
	UINT		nFlags;
} TIP_INFO;

#define EE_SHOW_TIP			(EE_FIRST+115)
// wParam = 0, (TIP_INFO*)lParam = pTipInfo
//

inline void Editor_ShowTip( HWND hwnd, TIP_INFO* pTipInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	SNDMSG( (hwnd), EE_SHOW_TIP, 0, (LPARAM)(TIP_INFO*)(pTipInfo) );
}

typedef struct _ACTIVE_STRING_INFO {
	UINT		cbSize;
	LPWSTR		pBuf;
	UINT		cchBuf;
	UINT		nFlags;
} ACTIVE_STRING_INFO;


#define EE_GET_ACTIVE_STRING	(EE_FIRST+116)
// wParam = 0, (LINK_INFO*)lParam = pInfo
//

inline int Editor_GetActiveString( HWND hwnd, ACTIVE_STRING_INFO* pInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_GET_ACTIVE_STRING, 0, (LPARAM)(ACTIVE_STRING_INFO*)(pInfo) );
}

#define FLAG_FILL_DEFAULT			0
#define FLAG_FILL_COPY				1
#define FLAG_FILL_SERIES			2
#define FLAG_FILL_FLASH				4
#define FLAG_FILL_TYPE_MASK			0x000f
#define FLAG_FILL_DONT_OVERWRITE	0x0100
#define FLAG_FILL_REPEAT			0x0200
#define FLAG_FILL_EXPAND_SELECTION	0x0400
#define FLAG_FILL_VALID_MASK		(FLAG_FILL_COPY | FLAG_FILL_SERIES | FLAG_FILL_FLASH | FLAG_FILL_DONT_OVERWRITE | FLAG_FILL_REPEAT | FLAG_FILL_EXPAND_SELECTION)

#define S_FILL_NONE					S_OK  // = 0
#define S_FILL_COPY					(HRESULT)(FLAG_FILL_COPY)
#define S_FILL_SERIES				(HRESULT)(FLAG_FILL_SERIES)
#define S_FILL_FLASH				(HRESULT)(FLAG_FILL_FLASH)

typedef struct _AUTOFILL_INFO {
	UINT		cbSize;
	POINT_PTR	ptSrcCellStart;
	POINT_PTR	ptSrcCellEnd;
	POINT_PTR	ptDestCellStart;
	POINT_PTR	ptDestCellEnd;
	DWORD		dwFlags;
	INT64       nIncrement;
} AUTOFILL_INFO;

#define EE_AUTOFILL		(EE_FIRST+117)
// wParam = 0, (AUTOFILL_INFO*)lParam = pInfo
//

inline HRESULT Editor_AutoFill( HWND hwnd, AUTOFILL_INFO* pInfo )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	return (int)SNDMSG( (hwnd), EE_AUTOFILL, 0, (LPARAM)(AUTOFILL_INFO*)(pInfo) );
}

#define COMPARE_SWAP_FILES				0x00000001
#define COMPARE_OLDER_FIRST				0x00000002
#define COMPARE_IGNORE_LEAD_SPACE		0x00000004
#define COMPARE_IGNORE_TRAIL_SPACE		0x00000008
#define COMPARE_IGNORE_EMBEDDED_SPACE	0x00000010
#define COMPARE_IGNORE_CASE				0x00000020
#define COMPARE_IGNORE_CRLF				0x00000040
#define COMPARE_IGNORE_COMMENT			0x00000080
#define COMPARE_SYNC_SCROLL_VERT		0x00000100
#define COMPARE_SYNC_SCROLL_HORZ		0x00000200
#define COMPARE_SYNC_CARET				0x00000400
#define COMPARE_TILE_VERT				0x00000800
#define COMPARE_TILE_HORZ				0x00001000
#define COMPARE_SWITCH_NO_WRAP			0x00002000
#define COMPARE_SAVE_OPTIONS			0x00004000
#define COMPARE_IGNORE_ENCODING			0x00008000
#define COMPARE_RESTORE_POS				0x00010000
#define COMPARE_QUIET					0x00020000
#define COMPARE_SYNC_SCROLL_ONLY		0x00040000
#define COMPARE_RESET					0x00080000
#define COMPARE_RESET_AFTER				0x00100000
#define COMPARE_GENERATE_REPORT			0x00200000
#define COMPARE_OPEN_REPORT				0x00400000
#define COMPARE_REPORT_DIFF_ONLY		0x00800000
#define COMPARE_REPORT_3_COL			0x10000000
#define COMPARE_NO_IGNORE_COMMENT		0x80000000 // used internally

#define COMPARE_QUALITY_1				0x01000000
#define COMPARE_QUALITY_2				0x02000000
#define COMPARE_QUALITY_3				0x03000000
#define COMPARE_QUALITY_4				0x04000000
#define COMPARE_QUALITY_5				0x05000000
#define COMPARE_QUALITY_MASK			0x07000000
#define COMPARE_QUALITY_DEF				COMPARE_QUALITY_3

#define MIN_COMPARE_QUALITY				1
#define MAX_COMPARE_QUALITY				5
#define DEF_COMPARE_QUALITY				3

#define DEF_COMPARE_OPTIONS				(COMPARE_TILE_VERT | COMPARE_SYNC_SCROLL_VERT | COMPARE_SYNC_SCROLL_HORZ | COMPARE_SYNC_CARET | COMPARE_SWITCH_NO_WRAP | COMPARE_RESTORE_POS | COMPARE_QUALITY_DEF)
#define DEF_SYNC_OPTIONS				(COMPARE_TILE_VERT | COMPARE_SYNC_SCROLL_VERT | COMPARE_SYNC_SCROLL_HORZ | COMPARE_SWITCH_NO_WRAP | COMPARE_RESTORE_POS | COMPARE_QUALITY_DEF)

#define COMPARE_OPTION_MASK				(COMPARE_IGNORE_LEAD_SPACE | COMPARE_IGNORE_TRAIL_SPACE | COMPARE_IGNORE_EMBEDDED_SPACE | COMPARE_IGNORE_CASE | COMPARE_IGNORE_CRLF | COMPARE_IGNORE_COMMENT | COMPARE_SYNC_SCROLL_VERT | COMPARE_SYNC_SCROLL_HORZ  | COMPARE_SYNC_CARET  | COMPARE_TILE_VERT  | COMPARE_TILE_HORZ  | COMPARE_SWITCH_NO_WRAP | COMPARE_IGNORE_ENCODING | COMPARE_RESTORE_POS | COMPARE_QUIET | COMPARE_SYNC_SCROLL_ONLY | COMPARE_RESET | COMPARE_RESET_AFTER | COMPARE_GENERATE_REPORT | COMPARE_OPEN_REPORT | COMPARE_REPORT_DIFF_ONLY | COMPARE_REPORT_3_COL | COMPARE_QUALITY_MASK )

typedef struct _COMPARE_INFO {
	UINT		cbSize;
	UINT		flags;
	LPCWSTR		pszDocument1;
	LPCWSTR		pszDocument2;
	LPCWSTR		pszResultFileName;
} COMPARE_INFO;

#define EE_COMPARE		(EE_FIRST+118)

inline int Editor_Compare( HWND hwnd, UINT nFlags, LPCWSTR pszDocument1, LPCWSTR pszDocument2, LPCWSTR pszResultFileName )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	COMPARE_INFO ci;
	ci.cbSize = sizeof( ci );
	ci.flags = nFlags;
	ci.pszDocument1 = pszDocument1;
	ci.pszDocument2 = pszDocument2;
	ci.pszResultFileName = pszResultFileName;
	return (int)SNDMSG( (hwnd), EE_COMPARE, (WPARAM)&ci, 0 );
}

// v19.1
typedef struct _UNICODE_NAME_INFO {
	UINT		cbSize;
	int         cchBuf;
	LPWSTR      pBuf;
	LPCWSTR     pstrSrc;
	int         cchSrc;
} UNICODE_NAME_INFO;


#define EE_GET_UNICODE_NAME  (EE_FIRST+119)

inline int Editor_GetUnicodeName( HWND hwnd, LPWSTR pBuf, int cchBuf, LPCWSTR pstrSrc, int cchSrc )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	UNICODE_NAME_INFO uni;
	uni.cbSize = sizeof( uni );
	uni.cchBuf = cchBuf;
	uni.pBuf = pBuf;
	uni.pstrSrc = pstrSrc;
	uni.cchSrc = cchSrc;
	return (int)SNDMSG( (hwnd), EE_GET_UNICODE_NAME, (WPARAM)&uni, 0 );
}

#define NUM_FLAG_FIXED_LINES			1  // internal use
#define NUM_FLAG_CAPITAL_LETTERS		2
#define NUM_FLAG_SKIP_EMPTY_LINES		4
#define NUM_FLAG_RESTART_NUM_EMPTY		8
#define NUM_FLAG_RESTART_NUM_DISCONTINUOUS  0x0010

#define NUM_FLAG_DECIMAL				0x0000
#define NUM_FLAG_HEXADECIMAL			0x0100
#define NUM_FLAG_OCTAL					0x0200
#define NUM_FLAG_BINARY					0x0300
#define NUM_FLAG_OTHER					0x0400
#define NUM_FLAG_TYPE_MASK              0x0700

typedef struct _NUMBERING_INFO {
	UINT cbSize;
	UINT nFlags;
	LPCWSTR pszFirst;
	LPCWSTR pszInc;
	INT64 nMaxLines;
} NUMBERING_INFO;

#define EE_NUMBERING (EE_FIRST+120)

inline HRESULT Editor_Numbering( HWND hwnd, LPCWSTR pszFirst, LPCWSTR pszInc, INT64 nMaxLines, UINT nFlags )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	NUMBERING_INFO ni;
	ni.cbSize = sizeof( ni );
	ni.pszFirst = pszFirst;
	ni.pszInc = pszInc;
	ni.nMaxLines = nMaxLines;
	ni.nFlags = nFlags;
	return (HRESULT)SNDMSG( (hwnd), EE_NUMBERING, (WPARAM)&ni, 0 );
}

#define COLUMN_MOVE			0
#define COLUMN_COPY			1
#define COLUMN_CONCAT		2
#define COLUMN_COALESCE		3
#define COLUMN_SPLIT_TO_COLUMNS	4
#define COLUMN_SPLIT_TO_LINES	5
#define COLUMN_ACTION_MASK	7

typedef struct _EDIT_COLUMN_INFO {
	UINT cbSize;
	UINT nFlags;
	int  iColumn1;
	int  iColumn2;
	int  iColumnTo;
	LPCWSTR pszInsert;
} EDIT_COLUMN_INFO;

#define EE_EDIT_COLUMN (EE_FIRST+121)

inline HRESULT Editor_EditColumn( HWND hwnd, UINT nFlags, int iColumnFrom1, int iColumnFrom2, int iColumnTo, LPCWSTR pszInsert )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	EDIT_COLUMN_INFO mi = { sizeof( mi ), nFlags, iColumnFrom1, iColumnFrom2, iColumnTo, pszInsert };
	return (HRESULT)SNDMSG( ( hwnd ), EE_EDIT_COLUMN, (WPARAM)&mi, 0 );
}

#define CSV_HALF_WIDTH			1
#define CSV_DISCARD_UNDO		2
#define MAX_CSV_FLAGS			(CSV_HALF_WIDTH | CSV_DISCARD_UNDO)

typedef struct _CONVERT_CSV_INFO {
	UINT cbSize;
	int  iDestMode;
	UINT nFlags;
	int  nSepCount;
	const int* pcxSepWidths;
} CONVERT_CSV_INFO;


#define EE_CONVERT_CSV (EE_FIRST+122)

inline HRESULT Editor_ConvertCsv( HWND hwnd, int iDestMode, UINT nFlags = 0, int nSepCount = 0, const int* pcxSepWidths = NULL )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	CONVERT_CSV_INFO info = { sizeof( info ), iDestMode, nFlags, nSepCount, pcxSepWidths };
	return (HRESULT)SNDMSG( hwnd, EE_CONVERT_CSV, (WPARAM)&info, 0 );
}

typedef struct _SPLIT_COLUMN_INFO {
	UINT cbSize;
	UINT nType;
	UINT nFlags;
	int  iColumn1;
	int  iColumn2;
	int  nLimit;
	LPCWSTR pszSeparator;
	LPCWSTR pszLocale;
} SPLIT_COLUMN_INFO;

#define EE_SPLIT_COLUMN (EE_FIRST+123)

inline HRESULT Editor_SplitColumn( HWND hwnd, UINT nType, UINT nFlags, int iColumnFrom1, int iColumnFrom2, int nLimit, LPCWSTR pszSeparator, LPCWSTR pszLocale )
{
	_ASSERT( hwnd && IsWindow( hwnd ) );
	SPLIT_COLUMN_INFO into = { sizeof( into ), nType, nFlags, iColumnFrom1, iColumnFrom2, nLimit, pszSeparator, pszLocale };
	return (HRESULT)SNDMSG( ( hwnd ), EE_SPLIT_COLUMN, (WPARAM)&into, 0 );
}

//
#define EE_LAST                 (EE_FIRST+255)

#define RUN_FILE				0
#define RUN_TEXT				1

#define HIGHLIGHT_COLOR_MASK	0x000f
#define HIGHLIGHT_WORD			0x0100
#define HIGHLIGHT_RIGHT_SIDE	0x0200
#define HIGHLIGHT_INSIDE_TAG	0x0400
#define HIGHLIGHT_REG_EXP		0x0800
#define HIGHLIGHT_CASE			0x1000
#define HIGHLIGHT_RIGHT_ALL		0x2000

#define FLAG_OPEN_OUTPUT			0x0001
#define FLAG_CLOSE_OUTPUT			0x0002
#define FLAG_FOCUS_OUTPUT			0x0004
#define FLAG_CLEAR_OUTPUT			0x0008
#define FLAG_INCLUDE_STDERR			0x0010
#define FLAG_GREP_OUTPUT			0x0020
#define FLAG_INSERT_VIEW			0x0040
#define FLAG_KEEP_DEST_RETURN_TYPE	0x0080
#define FLAG_STDIN					0x0100
#define FLAG_WAIT_FINISHED			0x0200
#define FLAG_CLOSE_ON_EXIT			0x0400
#define FLAG_ADD_EOF				0x0800

#define EI_GET_ENCODE           256
#define EI_SET_ENCODE           257
#define EI_GET_SIGNATURE        268
#define EI_SET_SIGNATURE        269
#define EI_GET_FONT_CHARSET     270
#define EI_SET_FONT_CHARSET     271
#define EI_GET_FONT_CP          272
#define EI_GET_INPUT_CP         274
#define EI_GET_SHOW_TAG         276
#define EI_SET_SHOW_TAG         277
#define EI_GET_FILE_NAMEA       278
#define EI_GET_FILE_NAMEW       280
#define EI_IS_PROPORTIONAL_FONT 282
#define EI_GET_NEXT_BOOKMARK    284
#define EI_GET_HILITE_FIND      286
#define EI_SET_HILITE_FIND      287
#define EI_GET_APP_VERSIONA     288
#define EI_GET_APP_VERSIONW     290
#define EI_GET_READ_ONLY        296
#define EI_IS_WINDOW_COMBINED   298
#define EI_WINDOW_COMBINE       299
#define EI_IS_UNDO_COMBINED     300

// new from v5
#define EI_GET_DOC_COUNT        301
#define EI_INDEX_TO_DOC         302
#define EI_DOC_TO_INDEX         303
#define EI_ZORDER_TO_DOC        304
#define EI_DOC_TO_ZORDER        305
#define EI_GET_ACTIVE_INDEX     306
#define EI_SET_ACTIVE_INDEX     307
#define EI_GET_FULL_TITLEA      308
#define EI_GET_FULL_TITLEW      309
#define EI_GET_SHORT_TITLEA     310
#define EI_GET_SHORT_TITLEW     311
#define EI_GET_SAVE_AS_TITLEA   312
#define EI_GET_SAVE_AS_TITLEW   313
#define EI_MOVE_ORDER           314
#define EI_CLOSE_DOC            315
#define EI_SAVE_DOC             316

// new from v7
#define EI_GET_CURRENT_FOLDER	317
#define EI_IS_LARGE_DOC			318
	
// new from v8
#define EI_USE_INI				319
#define EI_GET_LANGUAGE			320

// new from v9
#define EI_COMBINE_HISTORY      321
#define EI_GET_BAR_TEXT_COLOR	322
#define EI_GET_BAR_BACK_COLOR	323
#define EI_GET_RETURN_TYPE		324

// new from v10
#define EI_GET_ACTIVE_DOC		325
#define EI_SET_ACTIVE_DOC		326
#define EI_GET_SYNC_SESSION		327
#define EI_GET_LOC_DLL_INSTANCE	328

// new from v12
#define EI_GET_RES_DLL_INSTANCE	329

// new from v13
#define EI_GET_CMD_LIST_SIZE	330

// new from v14.4
#define EI_GET_DISCARD_UNDO		331
#define EI_SET_DISCARD_UNDO		332

// new from v14.6
#define EI_GET_HEADING_LINES	333
#define EI_SET_HEADING_LINES	334
#define EI_GET_NARROWING_TOP	335
#define EI_SET_NARROWING_TOP	336
#define EI_GET_NARROWING_BOTTOM	337
#define EI_SET_NARROWING_BOTTOM	348

#define EI_SET_HILITE_FILTER    349

// new from v15.2
#define EI_GET_CSV				350

// new from v15.4
#define EI_GET_PRINT_PAGES		351

// new from v15.5
#define EI_GET_COMBINE_HISTORY  352

// new from v15.8
#define EI_GET_CELL_MODE		353
#define EI_SET_CELL_MODE		354

// new from v16.0
#define EI_GET_UNTITLED			355

// new from v16.1.4
#define EI_GET_DPI				356

// new from v16.2
#define EI_GET_FILTER_VISIBLE_LINES_ABOVE	357
#define EI_SET_FILTER_VISIBLE_LINES_ABOVE	358
#define EI_GET_FILTER_VISIBLE_LINES_BELOW	359
#define EI_SET_FILTER_VISIBLE_LINES_BELOW	360

// new from v16.3
#define EI_GET_DPI_OPTIONS					361
#define EI_SET_DPI_OPTIONS					362

// new from v17.0
#define MAX_REG_NAME						40
#define EI_GET_REGISTERED_NAME				363

// new from v17.2
#define EI_VALIDATE_CSV						364
#define EI_GET_CLIENT_RECT_NO_BARS			365

// new from v17.5
#define EI_REFRESH_COMMON_SETTINGS			366

// new from v17.6
#define EI_GET_NEWLINE_CODE					367

// new from v17.8
#define EI_GET_MEMORY_SIZE					368
#define EI_SET_MEMORY_SIZE					369

// v17.9
#define EI_GET_BOOKMARK_COUNT				370

// v18.0
#define EI_SYNC_NOW							371

// v19.1
#define EI_GET_CHAR_TYPE                    372


#define SYNC_FLAG_FORCE				1				
#define SYNC_FLAG_SEND				2
#define SYNC_FLAG_RECEIVE			4
#define SYNC_FLAG_REFRESH_UI		8

#define VALIDATE_ADJUST_COLUMNS			0x00000001
#define VALIDATE_QUIET					0x00000002
#define VALIDATE_ADJUST_VISIBLE_ONLY	0x00000004
#define VALIDATE_DETECT_NL				0x00000008
#define VALIDATE_DONT_CLEAR_OUTPUT		0x00000010
#define VALIDATE_QUIET_IF_NO_ERROR		0x00000020
#define VALIDATE_ADJUST_ENLARGE_ONLY	0x00000040

#define CSV_ADJUSTED					0x00000001
#define CSV_NL_EMBEDDED					0x00000002
#define CSV_ABORT						0x00000004
#define CSV_INVALID_QUOTES				0x00000008
#define CSV_INCONSISTENT_COLUMNS		0x00000010
#define CSV_NOT_CSV						0x00000020
#define CSV_RETRY_SINGLE_THREAD			0x00000040  // internal use

#define DPI_OPTIONS_UNAWARE						0
#define DPI_OPTIONS_SYSTEM						1
#define DPI_OPTIONS_PER_MONITOR					2
#define DPI_OPTIONS_PER_MONITOR_V2				3
#define DPI_OPTIONS_RESIZE_WHEN_DPI_CHANGED		4

#define MAX_FILTER_VISIBLE_LINES_ABOVE	20
#define MAX_FILTER_VISIBLE_LINES_BELOW	20

#define MAX_COL_HEADINGS			8

#define POS_VIEW                    0
#define POS_LOGICAL_A               1
#define POS_LOGICAL_W               2
#define POS_TAB_A                   3
#define MAX_LINE_COLUMN_MODE		4
#define POS_CELL_LOGICAL			3  // same as POS_TAB_A, but never used together
#define POS_CELL					POS_CELL_LOGICAL  // obsolete
#define POS_CELL_VIEW				4

#define POS_SCROLL_DONT_CARE		0x00000000
#define POS_SCROLL_CENTER			0x00000010
#define POS_SCROLL_TOP				0x00000020
#define POS_SCROLL_ALWAYS			0x00000040
#define POS_WANT_X                  0x00010000
#define POS_WANT_Y                  0x00020000

#define SEL_TYPE_NONE               0
#define SEL_TYPE_CHAR               1
#define SEL_TYPE_LINE               2
#define SEL_TYPE_BOX                3
#define SEL_TYPE_CELL				4
#define SEL_TYPE_MASK               0x000f
#define SEL_TYPE_KEYBOARD           0x0010
#define SEL_TYPE_SELECTED           0x0020
#define SEL_TYPE_KEEP	            0x0040
#define SEL_TYPE_MULTI              0x0080

// EE_SAVE_FILE
#define DO_SAVE_NONE                0
#define DO_SAVE_REPLACE             1
#define DO_SAVE_RENAME              2

// EE_CONVERT
#define FLAG_MAKE_LOWER             0
#define FLAG_MAKE_UPPER             1
#define FLAG_HAN_TO_ZEN             2
#define FLAG_ZEN_TO_HAN             3
#define FLAG_CAPITALIZE             4
#define FLAG_NORM_FORM_C			5
#define FLAG_NORM_FORM_D			6
#define FLAG_NORM_FORM_KC			7
#define FLAG_NORM_FORM_KD			8
#define FLAG_NORM_ALL				5
#define MAX_NORM_FORM				4
#define FLAG_CONVERT_MASK           0x000f
#define FLAG_JAPANESE_YEN			0x0010
#define FLAG_KOREAN_WON				0x0020
#define FLAG_RIGHT_SINGLE_QUOTATION 0x0040  // v19.1
#define FLAG_RIGHT_DOUBLE_QUOTATION 0x0080  // v19.1
#define FLAG_CONVERT_SELECT_ALL     0x0100
#define FLAG_CONVERT_KATA           0x0400
#define FLAG_CONVERT_ALPHANUMERIC   0x0800
#define FLAG_CONVERT_MARK           0x1000
#define FLAG_CONVERT_SPACE          0x2000
#define FLAG_CONVERT_KANA_MARK      0x4000
#define FLAG_CONVERT_CUSTOM         0x8000  // v19.1
#define FLAG_CONVERT_ALL_TYPES      (FLAG_CONVERT_KATA | FLAG_CONVERT_ALPHANUMERIC | FLAG_CONVERT_MARK | FLAG_CONVERT_SPACE | FLAG_CONVERT_KANA_MARK)

// EE_FIND, EE_REPLACE, EE_FIND_IN_FILES, EE_REPLACE_IN_FILES, EE_MATCH_REGEX, EE_FIND_REGEX
#define FLAG_FIND_NEXT					0x0000'0000'0000'0001ull  // EE_FIND only
#define FLAG_FILTER_ENABLED				0x0000'0000'0000'0001ull  // internal use only
#define FLAG_FIND_BATCH_START			0x0000'0000'0000'0001ull  // internal use only
#define FLAG_FIND_CASE					0x0000'0000'0000'0002ull  // EE_FIND, EE_REPLACE, EE_FIND_IN_FILES and EE_REPLACE_IN_FILES, EE_MATCH_REGEX and EE_FIND_REGEX
#define FLAG_FIND_ESCAPE				0x0000'0000'0000'0004ull  // EE_FIND and EE_REPLACE, EE_FIND_IN_FILES and EE_REPLACE_IN_FILES
#define FLAG_REPLACE_SEL_ONLY			0x0000'0000'0000'0008ull  // EE_REPLACE only
#define FLAG_FIND_DETECT_WORD			0x0000'0000'0000'0008ull  // internal use only for "AddOccurrenceFlags" entry
#define FLAG_REPLACE_ALL				0x0000'0000'0000'0010ull  // EE_REPLACE only
#define FLAG_FIND_NO_PROMPT				0x0000'0000'0000'0020ull  // EE_FIND and EE_REPLACE
#define FLAG_FIND_ONLY_WORD				0x0000'0000'0000'0040ull  // EE_FIND, EE_REPLACE, EE_FIND_IN_FILES and EE_REPLACE_IN_FILES, and EE_FIND_REGEX
#define FLAG_FIND_AROUND				0x0000'0000'0000'0080ull  // EE_FIND only
#define FLAG_FIND_IGNORE_BINARY			0x0000'0000'0000'0080ull  // EE_FIND_IN_FILES and EE_REPLACE_IN_FILES (same as FLAG_FIND_AROUND) v15.1  // should be saved as "GrepFlag" entry
#define FLAG_FIND_REG_EXP				0x0000'0000'0000'0100ull  // EE_FIND, EE_REPLACE, EE_FIND_IN_FILES and EE_REPLACE_IN_FILES
#define FLAG_FIND_CLOSE					0x0000'0000'0000'0200ull  // EE_FIND and EE_REPLACE
#define FLAG_FIND_SHOW_IGNORED			0x0000'0000'0000'0200ull  // EE_FIND_IN_FILES and EE_REPLACE_IN_FILES (same as FLAG_FIND_CLOSE) v15.1  // should be saved as "GrepFlag" entry
#define FLAG_FIND_RECURSIVE				0x0000'0000'0000'0400ull  // EE_FIND_IN_FILES and EE_REPLACE_IN_FILES
#define FLAG_FIND_LOGICAL_OR			0x0000'0000'0000'0400ull  // EE_FILTER  (the value same as FLAG_FIND_RECURSIVE)
#define FLAG_FIND_FILENAMES_ONLY		0x0000'0000'0000'0800ull  // EE_FIND_IN_FILES only
#define FLAG_REPLACE_KEEP_OPEN			0x0000'0000'0000'1000ull  // EE_REPLACE_IN_FILES only
#define FLAG_FIND_CONTINUE				0x0000'0000'0000'1000ull  // EE_FILTER  (the value same as FLAG_REPLACE_KEEP_OPEN)
#define FLAG_REPLACE_BACKUP				0x0000'0000'0000'2000ull  // EE_REPLACE_IN_FILES only
#define FLAG_FIND_KEEP_PREVIOUS			0x0000'0000'0000'2000ull  // EE_FILTER  (the value same as FLAG_REPLACE_BACKUP)
#define FLAG_FIND_IGNORE_FILES			0x0000'0000'0000'4000ull  // EE_FIND_IN_FILES and EE_REPLACE_IN_FILES
#define FLAG_FIND_REMOVE_LAST			0x0000'0000'0000'4000ull  // EE_FILTER  (the value same as FLAG_FIND_IGNORE_FILES)
#define FLAG_FIND_OPEN_DOC				0x0000'0000'0000'8000ull  // EE_FIND and EE_REPLACE
#define FLAG_FIND_MATCH_DOT_NL			0x0000'0000'0001'0000ull  // internal use only
#define FLAG_FIND_INCREMENTAL			0x0000'0000'0002'0000ull  // internal use only
#define FLAG_FIND_SAVE_HISTORY			0x0000'0000'0004'0000ull  // EE_FIND, EE_REPLACE, EE_FIND_IN_FILES and EE_REPLACE_IN_FILES
#define FLAG_FIND_COUNT					0x0000'0000'0008'0000ull  // EE_FIND
#define FLAG_FIND_BOOKMARK				0x0000'0000'0010'0000ull  // EE_FIND
#define FLAG_FIND_SELECT_ALL			0x0000'0000'0020'0000ull  // EE_FIND
#define FLAG_FIND_WHOLE_STRING			0x0000'0000'0040'0000ull
#define FLAG_FIND_OUTPUT				0x0000'0000'0100'0000ull  // EE_FIND_IN_FILES only
#define FLAG_FIND_OUTPUT_DISPLAY		0x0000'0000'0200'0000ull  // EE_FIND_IN_FILES only (v14)
#define FLAG_GREP_NO_CLOSE				0x0000'0000'0400'0000ull  // EE_FIND_IN_FILES and EE_REPLACE_IN_FILES (v14)
#define FLAG_FIND_EXTRACT				0x0000'0000'0800'0000ull  // EE_FIND
#define FLAG_FIND_FILTER				0x0000'0000'1000'0000ull  // internal use only
#define FLAG_FIND_EMBEDDED_NL			0x0000'0000'2000'0000ull  // EE_FIND, EE_REPLACE and EE_FILTER for CSV embedded new lines
#define FLAG_FIND_NEGATIVE				0x0000'0000'4000'0000ull  // EE_FILTER
#define FLAG_FIND_UPDATE_MARKER			0x0000'0000'8000'0000ull  // internal use only
#define FLAG_FIND_EXTRACT_FILE_LINE		0x0000'0000'8000'0000ull  // internal use only for macros
#define FLAG_FILTER_DISABLED			0x0000'0000'8000'0000ull  // internal use only
#define FLAG_FIND_SEPARATE_CRLF			0x0000'0001'0000'0000ull
#define FLAG_FIND_REGEX_BOOST			0x0000'0002'0000'0000ull
#define FLAG_FIND_REGEX_ONIGMO			0x0000'0004'0000'0000ull
#define FLAG_FIND_REGEX_ENGINE_MASK     0x0000'0006'0000'0000ull
#define FLAG_FIND_INSERT_COLUMN			0x0000'0010'0000'0000ull  // EE_REPLACE only
#define FLAG_FIND_MATCH_NL				0x0000'0020'0000'0000ull
#define FLAG_FIND_CR_ONLY				0x0000'0040'0000'0000ull
#define FLAG_FIND_LF_ONLY				0x0000'0080'0000'0000ull
#define FLAG_FIND_CR_LF					0x0000'0100'0000'0000ull
#define FLAG_FIND_NL_OTHERS				0x0000'0200'0000'0000ull
#define FLAG_FIND_BOOKMARKED_ONLY		0x0000'0400'0000'0000ull
#define FLAG_FIND_UNBOOKMARKED_ONLY		0x0000'0800'0000'0000ull
#define FLAG_FIND_NUMBER_RANGE			0x0000'1000'0000'0000ull
#define FLAG_FIND_OUTPUT_ENCODING		0x0000'2000'0000'0000ull
#define FLAG_FIND_COUNT_FREQUENCY       0x0008'0000'0000'0000ull
#define FLAG_FIND_NO_OVERLAP			0x0040'0000'0000'0000ull
#define FLAG_FIND_LOOKAROUND			0x0080'0000'0000'0000ull
#define FLAG_FIND_REPLACE_LATER			0x0100'0000'0000'0000ull  // internal use only
#define FLAG_FIND_BOL					0x0200'0000'0000'0000ull
#define FLAG_FIND_EOL					0x0400'0000'0000'0000ull
#define FLAG_FIND_SINGLE_LINE			0x0800'0000'0000'0000ull  // internal use only
#define FLAG_FIND_LOWER_INTERNAL		0x2000'0000'0000'0000ull  // internal use only
#define FLAG_FIND_ADD_NEXT				0x4000'0000'0000'0000ull  // EE_FIND internal use only
#define FLAG_FIND_NO_DESELECT			0x8000'0000'0000'0000ull  // EE_FIND internal use only

#define FLAG_FIND_SEL_ONLY				FLAG_REPLACE_SEL_ONLY  // EE_FIND only

#define FLAG_FIND_LINE_ONLY				(FLAG_FIND_OUTPUT_DISPLAY)  // EE_FIND_IN_FILES only
#define FLAG_FIND_MATCHED_ONLY			(FLAG_FIND_FILENAMES_ONLY+FLAG_FIND_OUTPUT_DISPLAY)
														  
#define FLAG_FIND_OPEN_DIRECT			(FLAG_FIND_FILTER)
#define FLAG_FIND_OPEN_FILTER			(FLAG_FIND_OUTPUT+FLAG_FIND_FILTER)

#define FLAG_FIND_BOL_EOL				(FLAG_FIND_BOL | FLAG_FIND_EOL)

#define FLAG_GREP_MASK				   (0x0000'0007'0604'7d46ull | FLAG_FIND_OUTPUT | FLAG_FIND_FILTER | FLAG_FIND_NUMBER_RANGE | FLAG_FIND_COUNT_FREQUENCY | FLAG_FIND_OUTPUT_ENCODING)
#define FLAG_FIND_EXTRACT_MASK			(FLAG_FIND_FILENAMES_ONLY | FLAG_FIND_OUTPUT_DISPLAY | FLAG_FIND_OUTPUT | FLAG_FIND_COUNT_FREQUENCY)
#define FLAG_FIND_MASK_WITHOUT_EXTRACT (0x0000'0007'283f'83ffull | FLAG_FIND_BOL_EOL | FLAG_FIND_LOOKAROUND | FLAG_FIND_INSERT_COLUMN | FLAG_FIND_NUMBER_RANGE)
#define FLAG_FIND_MASK					(FLAG_FIND_MASK_WITHOUT_EXTRACT | FLAG_FIND_EXTRACT_MASK)
#define FLAG_BATCH_FIND_MASK			(FLAG_FIND_CASE | FLAG_FIND_ONLY_WORD | FLAG_FIND_REG_EXP | FLAG_FIND_NUMBER_RANGE | FLAG_FIND_ESCAPE)
#define FLAG_BATCH_GREP_MASK			FLAG_BATCH_FIND_MASK
#define FLAG_FILTER_MASK				(FLAG_FIND_CASE | FLAG_FIND_ESCAPE | FLAG_FIND_ONLY_WORD | FLAG_FIND_REG_EXP | FLAG_FIND_INCREMENTAL | FLAG_FIND_NEGATIVE | FLAG_FIND_NUMBER_RANGE)
#define FLAG_ADVANCED_FILTER_MASK		(FLAG_FILTER_MASK | FLAG_FIND_LOGICAL_OR | FLAG_FIND_WHOLE_STRING | FLAG_FILTER_ENABLED | FLAG_FIND_MATCH_NL | FLAG_FIND_CR_ONLY | FLAG_FIND_LF_ONLY | FLAG_FIND_CR_LF | FLAG_FIND_NL_OTHERS | FLAG_FIND_BOOKMARKED_ONLY | FLAG_FIND_UNBOOKMARKED_ONLY)
#define FLAG_MACRO_FILTER_MASK			((FLAG_ADVANCED_FILTER_MASK | FLAG_FIND_CONTINUE | FLAG_FIND_KEEP_PREVIOUS | FLAG_FIND_REMOVE_LAST) & ~FLAG_FILTER_ENABLED)
#define FLAG_FIND_SAVE_MASK				((FLAG_GREP_MASK | FLAG_FIND_MASK) & ~(FLAG_FIND_NO_PROMPT | FLAG_FIND_BOOKMARK | FLAG_FIND_SAVE_HISTORY | FLAG_FIND_SELECT_ALL | FLAG_FIND_ADD_NEXT | FLAG_FIND_EXTRACT))

#define FLAG_FIND_NOT_ONCE              (FLAG_FIND_COUNT | FLAG_FIND_SELECT_ALL | FLAG_FIND_REPLACE_LATER)  // internal use only
#define FLAG_FIND_SEARCH_ALL			(FLAG_FIND_COUNT | FLAG_FIND_BOOKMARK | FLAG_FIND_SELECT_ALL | FLAG_FIND_EXTRACT | FLAG_FIND_FILTER | FLAG_FIND_UPDATE_MARKER | FLAG_FIND_REPLACE_LATER)  // internal use only
#define FLAG_FIND_RETURN_COUNT			(FLAG_FIND_COUNT | FLAG_FIND_BOOKMARK | FLAG_FIND_SELECT_ALL | FLAG_FIND_EXTRACT | FLAG_FIND_FILTER | FLAG_REPLACE_ALL )  // internal use only
#define FLAG_FIND_SAVE_UNIQUE_MASK		(FLAG_FIND_IGNORE_BINARY | FLAG_FIND_SHOW_IGNORED | FLAG_FIND_OUTPUT | FLAG_FIND_FILTER | FLAG_FIND_FILENAMES_ONLY | FLAG_FIND_OUTPUT_DISPLAY)  // internal use only

#define DEFAULT_FIND_FLAG				(FLAG_FIND_AROUND | FLAG_FIND_OUTPUT_DISPLAY)
#define DEFAULT_GREP_FLAG				(FLAG_FIND_SHOW_IGNORED)
#define DEFAULT_ADD_OCCURRENCE			(FLAG_FIND_CASE | FLAG_FIND_ONLY_WORD)
#define DEFAULT_FILTER_FLAG				(FLAG_FIND_INCREMENTAL)
#define DEFAULT_EXTRACT_FREQ_FLAG       (FLAG_FIND_CASE)
#define DEFAULT_GREP_EXTRACT_FLAG       (FLAG_FIND_OUTPUT_DISPLAY | FLAG_FIND_FILENAMES_ONLY)
#define FLAG_GREP_EXTRACT_MASK          (FLAG_FIND_OUTPUT_DISPLAY | FLAG_FIND_FILENAMES_ONLY | FLAG_FIND_COUNT_FREQUENCY | FLAG_FIND_OUTPUT)

// FLAG_FIND_OUTPUT_DISPLAY = 0, FLAG_FIND_FILENAMES_ONLY = 0 : Displays file names and lines  OUTPUT_DISPLAY_FILE_AND_LINE
// FLAG_FIND_OUTPUT_DISPLAY = 0, FLAG_FIND_FILENAMES_ONLY = 1 : Displays file names only       OUTPUT_DISPLAY_FILE_ONLY
// FLAG_FIND_OUTPUT_DISPLAY = 1, FLAG_FIND_FILENAMES_ONLY = 0 : Displays matched lines only    OUTPUT_DISPLAY_LINE_ONLY
// FLAG_FIND_OUTPUT_DISPLAY = 1, FLAG_FIND_FILENAMES_ONLY = 1 : Displays matched strings only  OUTPUT_DISPLAY_MATCHED_ONLY


// GET_LINE_INFO
#define FLAG_LOGICAL			1
#define FLAG_WITH_CRLF			2
#define FLAG_GET_CRLF_BYTE		4

#define UNINSTALL_FALSE			0
#define UNINSTALL_SIMPLE_DELETE	1
#define UNINSTALL_RUN_COMMAND	2

#define EP_FIRST                (WM_USER+0x500)

#define EP_QUERY_PROPERTIES     (EP_FIRST+0)
#define EP_SET_PROPERTIES       (EP_FIRST+1)
#define EP_GET_NAMEA            (EP_FIRST+2)
#define EP_GET_NAMEW            (EP_FIRST+3)
#define EP_GET_VERSIONA         (EP_FIRST+4)
#define EP_GET_VERSIONW         (EP_FIRST+5)
#define EP_QUERY_UNINSTALL      (EP_FIRST+6)
#define EP_SET_UNINSTALL        (EP_FIRST+7)
#define EP_GET_BITMAP           (EP_FIRST+8)
#define EP_GET_MASK             (EP_FIRST+9)
#define EP_GET_INFO             (EP_FIRST+10)
#define EP_PRE_TRANSLATE_MSG	(EP_FIRST+11)
#define EP_USE_DROPPED_FILES	(EP_FIRST+12)
#define EP_GET_MENU_TEXT		(EP_FIRST+13)
#define EP_GET_STATUS_MESSAGE	(EP_FIRST+14)
#define EP_DISABLE_AUTO_COMPLETE	(EP_FIRST+15)
#define EP_USER_MSG				(EP_FIRST+16)

#define EP_LAST                 (EP_FIRST+50)

#ifdef _UNICODE
#define EP_GET_NAME             EP_GET_NAMEW
#define EP_GET_VERSION          EP_GET_VERSIONW
#else
#define EP_GET_NAME             EP_GET_NAMEA
#define EP_GET_VERSION          EP_GET_VERSIONA
#endif

// EP_GET_BITMAP
#define BITMAP_SMALL            0x00000000
#define BITMAP_LARGE            0x00000001
#define BITMAP_SIZE_MASK        0x0000000f
#define BITMAP_16_COLOR         0x00000000
#define BITMAP_256_COLOR        0x00000010
#define BITMAP_24BIT_COLOR      0x00000020
#define BITMAP_COLOR_MASK       0x000000f0
#define BITMAP_DEFAULT          0x00000000
#define BITMAP_DISABLED         0x00000100
#define BITMAP_HOT              0x00000200
#define BITMAP_STATUS_MASK      0x00000f00

// EP_GET_INFO
#define EPGI_ALLOW_OPEN_SAME_GROUP      1
#define EPGI_MAX_EE_VERSION             2
#define EPGI_MIN_EE_VERSION             3
#define EPGI_SUPPORT_EE_PRO             4
#define EPGI_SUPPORT_EE_STD             5
#define EPGI_ALLOW_MULTIPLE_INSTANCES	6

#define CHECK_FILE_CHANGED_NONE         0
#define CHECK_FILE_CHANGED_PROMPT       1
#define CHECK_FILE_CHANGED_AUTO         2
#define CHECK_FILE_CHANGED_EXCLUSIVE    3
#define MAX_CHECK_FILE_CHANGED			4

#define MIN_MONITOR_INTERVAL            1
#define MAX_MONITOR_INTERVAL            255  // inclusive
#define DEF_MONITOR_INTERVAL            5

#define MIN_SMOOTH_SCROLL_SPEED	1
#define MAX_SMOOTH_SCROLL_SPEED	9
#define DEF_SMOOTH_SCROLL_SPEED 5

#define MAX_REGEX_INDENT				512

#define SIZE_OF_CUSTOMIZE_INFO_OLD      6660   // old size before v9
#define SIZE_OF_CUSTOMIZE_INFO_2        ((MAX_REGEX_INDENT*4)*sizeof(WCHAR))
#define SIZE_OF_CUSTOMIZE_INFO_V9      (SIZE_OF_CUSTOMIZE_INFO_OLD+SIZE_OF_CUSTOMIZE_INFO_2)   // new size v9

#define MAX_PAREN_SIZE	11
#define DEF_PAREN_BITS	0x07f7
#define HTML_PAREN_BITS 0x07ff

#define HIGHLIGHT_SELECTION_NONE		0
#define HIGHLIGHT_SELECTION_SELECT_ONLY	1
#define HIGHLIGHT_SELECTION_WORD		2

#define REGEX_INDENT_NONE				0
#define REGEX_INDENT_ALLOW_ALL			1
#define REGEX_INDENT_NL_ONLY			2

#define SCROLL_FLAG_MARKS				1
#define SCROLL_FLAG_SHOW_MODIFIED		2
#define SCROLL_FLAG_SHOW_BOOKMARKS		4
#define SCROLL_FLAG_SHOW_FIND			8
#define SCROLL_FLAG_SHOW_CARET			0x10
#define SCROLL_FLAG_MINIMAP				0x20
#define SCROLL_FLAG_SHOW_ENTIRE			0x40
#define SCROLL_FLAG_SHOW_ARROWS			0x80
#define SCROLL_FLAG_LINE_LOOP_ALL		(SCROLL_FLAG_SHOW_MODIFIED | SCROLL_FLAG_SHOW_BOOKMARKS | SCROLL_FLAG_SHOW_FIND | SCROLL_FLAG_MINIMAP)
#define SCROLL_FLAG_DEFAULT				(SCROLL_FLAG_MARKS | SCROLL_FLAG_SHOW_MODIFIED | SCROLL_FLAG_SHOW_BOOKMARKS | SCROLL_FLAG_SHOW_FIND)

#define SCROLL_FLAG_EX_SCROLL_2_LINES	1
#define SCROLL_FLAG_EX_3D_LOOK			2
#define SCROLL_FLAG_EX_MINIMAP_HOVER	4


#define MIN_ZOOM_PERCENT		1
#define MAX_ZOOM_PERCENT		80
#define DEF_ZOOM_PERCENT		40
#define INC_ZOOM_PERCENT		1   // was 5
#define PAGE_ZOOM_PERCENT		20
#define TICFREQ_ZOOM_PERCENT	10

#define MIN_ASPECT_PERCENT		1
#define MAX_ASPECT_PERCENT		100
#define DEF_ASPECT_PERCENT		100
#define INC_ASPECT_PERCENT		1   // was 5
#define PAGE_ASPECT_PERCENT		20
#define TICFREQ_ASPECT_PERCENT	10

#define UPPER_INDENT			255
#define LOWER_INDENT			1
#define DEF_INDENT				8

#define DEF_HIGHLIGHT_NONE		0
#define DEF_HIGHLIGHT_ONLY		1
#define DEF_HIGHLIGHT_ADD		2

#define UNTITLED_NAME			1
#define UNTITLED_NO_SEQ_NUM		2

#define LINE_NUM_SHOW			1
#define LINE_NUM_ZERO_BASE		2

#define PROMPT_CRLF_NONE		0
#define PROMPT_CRLF_PROMPT		1
#define PROMPT_CRLF_NO_BINARY	2

#define DELETE_SPACE_END_NO				0
#define DELETE_SPACE_END_YES			1
#define DELETE_SPACE_END_EXCEPT_CURSOR	2

#define VALIDATOR_SHOW_NONE			0
#define VALIDATOR_SHOW_OPENED		1
#define VALIDATOR_SHOW_ON_ERRORS	2
#define VALIDATOR_SHOW_MASK			3

#define VALIDATOR_ENABLED			4

#define VALIDATOR_TYPE_HTML			0x00
#define VALIDATOR_TYPE_CSS			0x10
#define VALIDATOR_TYPE_JSON			0x20
#define VALIDATOR_TYPE_CSV			0x30
#define VALIDATOR_TYPE_XML			0x40
#define VALIDATOR_TYPE_MASK			0x70
#define MAX_VALIDATOR_TYPE			5

#define DEF_VALIDATOR_HTML			(VALIDATOR_ENABLED | VALIDATOR_SHOW_ON_ERRORS | VALIDATOR_TYPE_HTML)
#define DEF_VALIDATOR_CSS			(VALIDATOR_ENABLED | VALIDATOR_SHOW_ON_ERRORS | VALIDATOR_TYPE_CSS)
#define DEF_VALIDATOR_JSON			(VALIDATOR_ENABLED | VALIDATOR_SHOW_ON_ERRORS | VALIDATOR_TYPE_JSON)
#define DEF_VALIDATOR_CSV			(VALIDATOR_ENABLED | VALIDATOR_SHOW_ON_ERRORS | VALIDATOR_TYPE_CSV)
#define DEF_VALIDATOR_XML			(VALIDATOR_ENABLED | VALIDATOR_SHOW_ON_ERRORS | VALIDATOR_TYPE_XML)

class CCustomizeInfo
{
public:
    LOGFONTW    m_alfScreen[MAX_CHARSET];   // screen fonts
    LOGFONTW    m_alfPrint[MAX_CHARSET];    // printer fonts
    POINT       m_ptShowScrollBar;      // scroll bars (x: horizontal and y: vertical) 0: no display, 1: display only when necessary, 2: display always
    int         m_nPrinterMarginTop;    // printer top margin  (in 1/1000 inch) (0 - USHRT_MAX (32767))
    int         m_nPrinterMarginBottom; // printer bottom margin
    int         m_nPrinterMarginLeft;   // printer left margin
    int         m_nWrapMode;        // wrap mode (WRAP_NONE - MAX_WRAP_MODE-1)
    int         m_nMarginNormal;    // normal line margin (MIN_MARGIN - MAX_MARGIN)
    int         m_nMarginQuote;     // quoted line margin (MIN_MARGIN - MAX_MARGIN)
    int         m_nTabSpace;        // tab columns (LOWER_INDENT - UPPER_INDENT)
    int         m_nEncodingRead;    // encoding for read (1 - CODEPAGE_HEX)
	char		m_nLineSpace;		// line space  (MIN_LINE_SPACE - MAX_LINE_SPACE-1) 
	char		m_nCharSpace;		// v7: character space  (MIN_CHAR_SPACE - MAX_CHAR_SPACE-1)
	WORD		m_wParenPairBits;   // PRO only  v9: Paren Pairs to highlight/autocomplete Bits  
	char		m_nLineSpacePrint;  // space between lines  (MIN_LINE_SPACE - MAX_LINE_SPACE-1)
    bool        m_bAutoCompleteParen;  // PRO only  v9: Auto Complete corresponding bracket
	BYTE		m_byteMinimapAspectPercent;  // v16.3
	BYTE		m_byteDefHighlight;          // (DEF_HIGHLIGHT_NONE (0) - DEF_HIGHLIGHT_ADD (2))
    UINT        m_nAS;      //  was m_nHiliteTag before v3.16
	bool		m_bShowUserDefinedGuides;  // v14.2
	BYTE		m_byteScrollFlags;
	bool		m_bTrackChanges;
	bool		m_bPreferUtf8;		// v14.6
    UINT        m_nAutoSaveTime;    // PRO only  auto save time  (0 - MAX_AUTO_SAVE_TIME (9999))
    int         m_nCheckFileChanged; // v3: changed by another program  (0 - MAX_CHECK_FILE_CHANGED-1)
	BYTE        m_byteDummy4;      // was        m_nDummy; // m_nUndoBufferSize;  // PRO only  undo max number
	BYTE        m_byteDummy3;
	BYTE        m_byteDummy2;
	BYTE        m_byteDummy1;
    int         m_nEncodingNew;     // v3: encoding for new files  (1 - CODEPAGE_HEX)
    int         m_nCrLfNew;         // v3: how to return for new files  (FLAG_CR_AND_LF - FLAG_LF_ONLY)
	bool         m_bShowOneLineAbove;     // v15.4
	bool         m_bRememberVisitedLinks; // v15.4
	bool         m_bFixedPitchFont;
	BYTE		m_byteMinimapZoomPercent;  // v16.3
    int         m_nEncodingWrite;   // PRO only v3: encoding for saving    (1 - CODEPAGE_HEX)
    int         m_nCrLfWrite;       // PRO only v3: how to return for saving  (SAVE_CRLF_NONE (0) - SAVE_CRLF_LF_ONLY (3))
    int         m_nSpecialSyntax;   // v3.16: Special Syntax  (SPECIAL_SYNTAX_NONE (0) - MAX_SPECIAL_SYNTAX-1 (2))
    WCHAR       m_chEscape;         // v3.16: Escape character
    bool        m_bPasteAnsi;       // PRO only v3.16: Always Paste as ANSI
    bool        m_bNewTemplate;     // v3.17: Use template for a new file
    bool        m_bSaveAsNameEntity; // v3.17: Use Named Entity Reference
    bool        m_bInsertSpacesTab; // v3.19: Insert spaces for Tab
    WCHAR       m_chIndentBegin;    // v3.17: Begin Indent
    WCHAR       m_chIndentEnd;      // v3.17: End Indent
    WCHAR       m_chEndOfStatement; // v3.17: End of Statement
    int         m_nIndentSpace;     // v3.19: Indent columns  (LOWER_INDENT (1) - UPPER_INDENT (255))
    bool        m_bNoSpaceEdge;     // v3.19: No space at left edge of Window
    BYTE        m_byteOpenFileInQuotes;       // obsolete   (OPEN_FILE_IN_QUOTES_NONE (0) - OPEN_FILE_IN_QUOTES_ASSOCIATED (2))
    bool        m_bShowScrollOnlyActive; // v3.31: Show scroll bars only when current pane is active
    bool        m_bWrapPagePrint;   // v3.31: Wrap by Page when printing
    int         m_nPrinterMarginRight;  // v3.24: printer right margin
    int         m_nMaxFindHilite;       // PRO only v3.32: (Depth of searched string to highlight) - 1   ((-1) - 29)
    bool        m_bPromptInvalidChar; // v4.01: Prompt if invalid characters found
    BYTE        m_byteUntitled;        // auto name untitled  (0 - 3)
    BYTE        m_byteMonitorInterval;  // PRO only 5.00: monitor interval for changed file (File tab)  (MIN_MONITOR_INTERVAL - MAX_MONITOR_INTERVAL)
    bool        m_bVirtualSpace;    // PRO only 7.00 : Enable Virtual Space
	BYTE		m_byteSmoothScrollSpeed;	// 7.00 : Smooth Scroll Speed  MIN_SMOOTH_SCROLL_SPEED (slow) - MAX_SMOOTH_SCROLL_SPEED (fast)
	bool		m_bShowIndentGuides;        // PRO only 8.00 : Show Indent Guides
	bool		m_bHorzGrid;		// PRO only v10: Horizontal Grid (was m_bDottedLine)
	bool		m_bSelectInURL;   // obsolete   // PRO only 9.00 : Clicking in URL selects the whole string
	BYTE		m_bRegexIndent;  // (REGEX_INDENT_NONE (0) - REGEX_INDENT_NL_ONLY (2))
	BYTE		m_byteDetectSV;					// bool		m_bDetectCSV;
	bool		m_bDetectTSV;		// PRO only v9 : Detect TSV
	bool		m_bDetectDSV;		// PRO only v9 : Detect DSV (user-defined delimiter)
	bool		m_bSpellQuote;         // PRO only 
	bool		m_bSpellSingleQuotes;  // PRO only 
	bool		m_bSpellDoubleQuotes;  // PRO only 
	bool		m_bSpellComment;	    // PRO only 
	bool		m_bSpellScript;		    // PRO only 
	bool		m_bSpellInTag;		    // PRO only 
	bool		m_bSpellHilite;		    // PRO only 
	bool		m_bSpellHyperlink;	    // PRO only 
	bool		m_bSpellRest;		    // PRO only 
	bool		m_bSpell;			    // PRO only 
	bool		m_bSpellCamelCase;	    // PRO only 
	bool		m_bHighlightCharRef;	// PRO only v11 Highlight HTML/XML Character Reference and Universal Character Names
	bool		m_bEnableHeader;
	bool		m_bEnableFooter;
	bool		m_bHighlightMatchingTag;  // PRO only  v12 Highlight Matching Tag
	bool		m_bPromptRename;    // v13  Prompt before Deleting a Old File When Renaming
    BYTE        m_abUrlChar[128];   // =1: URL char, =2: URL char byte not at end.
    bool        m_bNotepadDiary;    // notepad compatible diary
    bool        m_bPrintLineNum;    // print line numbers
    bool        m_bPromptNullFile;  // prompt if Null character found
    BYTE        m_bytePromptCrLf;      // prompt at inconsistent returns (0 - 3)
    bool        m_bShowEOF;         // show EOF
    bool        m_bShowCR;          // show returns
    bool        m_bShowTab;         // show tab
    BYTE        m_byteShowLineNum;     // show line numbers  (0 - 3)
    BYTE        m_bShowLogicalLine; // line and column display as (POS_VIEW (0) - MAX_LINE_COLUMN_MODE-1 (3))
    bool        m_bWordWrap;        // word wrap
    bool        m_bFaceWrap;        // PRO only enable non-wrap words
    bool        m_bKinsokuWrap;     // wrap these characters
    bool        m_bSaveTabToSpace;  // PRO only save tabs as spaces
    bool        m_bSaveInsertCR;    // PRO only insert returns when saving
    bool        m_bUseRecycleBin;   // PRO only use recylce bin to buckup
    bool        m_bAutoIndent;      // auto indent
    BYTE		m_bWrapIndent;		// PRO only v7.00: auto indent for wrap position, used to be m_bOverwrite, v6.00 Obsolete, a combination of two bits: 1 : on (include full-width space), 2 : on (ignore full-width space)
    bool        m_bHilite;          // highlight these words
    bool        m_bDummy6;	      // was m_bURL;             // link to URLs
    bool        m_bDummy5;      // was m_bMailTo;          // clicking mail address sends mail
    bool        m_bLinkDblclick;      // obsolete  // PRO only enable double clicking only
    bool        m_bFullPath;        // PRO only show file name with full path
	BYTE        m_byteValidator;      // was bool m_b7BitKanji;       // OBSOLETE  7 bit kanji  
    bool        m_bCrLfSeparateMark;    // PRO only  show CR and LF with different marks 
    bool        m_bShowRuler;       // show ruler
    bool        m_bAutoSave;        // PRO only auto save
    bool        m_bDeleteEmpty;     // PRO only delete empty files when saving
    bool        m_bSaveNotModified; // PRO only always enable saving
    bool        m_bBackupFolder;            // save backups to backup folder
    bool        m_bFolderIfRecycleFailed;   // PRO only save to backup folder if recycle bin not available
    bool        m_bAutoSaveFolder;          // PRO only save to auto save folder
    bool        m_bRenameBackup;            // PRO only rename if same file name exists
    bool        m_bControlIME;              // run input method editor
    bool        m_bRenameAutoSave;          // PRO only rename if same file name exists
    bool        m_bBackupSame;              // PRO only save backups to same folder
    bool        m_bShowDbSpace;             // show double-byte spaces
    bool        m_bInitialFolder;		    // v14.1: Specify Initial Folder
    bool        m_bPageVScroll;             // v3: always enable 1page vertical scroll
    bool        m_bPageHScroll;             // v3: always enable 1page horizontal scroll
    bool        m_bHalfPageScroll;          // PRO only v3: scroll half page
    bool        m_bDetectUnicode;           // v3: detect Unicode(UTF-16/UTF-8)signature (BOM)
    bool        m_bAllowCtrlChars;          // PRO only v3: allow insert control character
    bool        m_bMoveCursorScroll;        // PRO only v3: move cursor by scrolling
    bool        m_bHorzLine;                // v3: horizontal line
    bool        m_bVertLine;                // v3: vertical line
	BYTE        m_byteScrollFlagsEx;            // PRO only v3: double line scroll  (0 - 3)
    bool        m_bFastKeyRepeat;           // PRO only v3: faster cursor movement
    bool        m_bDBCharUrl;               // PRO only v3: recognize double-byte characters as URLs
    bool        m_bKanaUrl;                 // PRO only v3: recognize single-byte kana and kana marks as URLs
    bool        m_bShowPage;                // PRO only v3: display page number
    bool        m_bUsePrinterFont;          // v3: choose font for default printer
    bool        m_bSignatureNew;            // PRO only v3: Unicode, UTF-8 signature for new files
    bool        m_bPromptNotAnsi;           // v3: prompt on saving if unicode characters cannot convert to ANSI
    bool        m_bSignatureWrite;          // PRO only  v3: Unicode, UTF-8 signature for saving
    bool        m_bIgnoreColorPrint;        // v3.08: Ignore Color and Underlines (Print)
    bool        m_bNoFullPathIfNotActive;   // v3.08: Display file name without full path if the window is not active
    bool        m_bSmoothScroll;            // v7.00: Smooth Scroll, used to be m_bSaveOverwrite, v6.00 Obsolete
    bool        m_bNoChangeCrLf;            // PRO only v3.13: Do not change how to return at copy and paste.
    bool        m_bShowSpace;               // v3.13: show single-byte spaces
    bool        m_bWordWrapMark;            // v3.13: allows word wrap after marks
    bool        m_bPrintSeparatingLines;    // v3.14: Draw separating lines
    bool        m_bSameFontPrint;           // v3.14: Use Display Font as Printer Font
    bool        m_bHiliteCorresParen;       // PRO only v3.14: Highlight Corresponding Parentheses
    bool        m_bSelectInQuotes;           // obsolete   // PRO only v3.14: Highlight and easily select in "quotes".
    bool        m_bDetectUTF8;              // v3.15: Detect UTF-8
    bool        m_bDetectCharset;           // v3.15: Detect Charset (HTML)
    bool        m_bDetectAll;               // v3.15: Detect All
    BYTE        m_byteDeleteSpaceEnd;          // PRO only v3.15: Delete Space at End of Lines
    bool        m_bSaveAsEntity;            // v3.15: Encode Unicode as HTML Entity
    bool        m_bShowControl;             // PRO only v3.15: Highlight Control Characters
    BYTE        m_bQuoteType;               // v3.16: Quote type, combination of QUOTE_SINGLE, QUOTE_DOUBLE and QUOTE_CONTINUE  (0 - 7)
    WCHAR       m_chKanjiInChar;            // OBSOLETE transitional character to kanji
    WCHAR       m_chKanjiOutChar;           // OBSOLETE transitional character to single-bytes 
    WCHAR       m_chTagLeft;                // begin tag
    WCHAR       m_chTagRight;               // end tag
    WCHAR       m_szHeader[MAX_HEADER];             // header
    WCHAR       m_szLineComment1[MAX_LINE_COMMENT]; // v3.16: Line Comment (obsolete)
    WCHAR       m_szScriptBegin[MAX_SCRIPT_BEGIN];  // v3.16: Script Begin
    WCHAR       m_szFooter[MAX_FOOTER];             // footer
    WCHAR       m_szLineComment2[MAX_LINE_COMMENT]; // v3.16: Line Comment (obsolete)
    WCHAR       m_szScriptEnd[MAX_SCRIPT_END];      // v3.16: Script End
    WCHAR       m_szPrefix[MAX_PREFIX_LENGTH];      // default quote mark 
    WCHAR       m_szKinsokuBegin[MAX_KINSOKU_BEGIN]; // not allowed at line head
    WCHAR       m_szKinsokuEnd[MAX_KINSOKU_END];    //  not allowed at line end
    WCHAR       m_szDefExt[MAX_DEF_EXT];            // default extension
    WCHAR       m_szPrefixList[MAX_PREFIX_LIST];    // quote mark 
    WCHAR       m_szBackupPath[MAX_PATH];           // backup folder
    WCHAR       m_szAutoSavePath[MAX_PATH];         // PRO only auto save folder
    WCHAR       m_szMultiCommentBegin[MAX_MULTI_COMMENT_BEGIN];  // Multi-line comment begin
    WCHAR       m_szMultiCommentEnd[MAX_MULTI_COMMENT_END];      // Multi-line comment end
public:
    WCHAR       m_szRegexIgnoreIndent[MAX_REGEX_INDENT];
    WCHAR       m_szRegexIndentBegin[MAX_REGEX_INDENT];
    WCHAR       m_szRegexIndentEnd[MAX_REGEX_INDENT];
    WCHAR       m_szRegexIndentStatement[MAX_REGEX_INDENT];
	WCHAR		m_szNewLineComment1[MAX_NEW_LINE_COMMENT];  // v14.1 Line Comment
	WCHAR		m_szNewLineComment2[MAX_NEW_LINE_COMMENT];  // v14.1 Line Comment
	WCHAR		m_szInitialFolder[MAX_PATH];
	WCHAR		m_szTemplateFile[MAX_PATH];                 // v17.0
	WCHAR		m_szConfigCopiedFrom[MAX_DEF_CONFIG_NAME];  // v17.0
    
public:
    void Initialize();
	bool IsSpellInCheckedAny() const {
		return m_bSpellQuote || m_bSpellSingleQuotes || m_bSpellDoubleQuotes || m_bSpellComment || m_bSpellScript || m_bSpellInTag || m_bSpellHilite || m_bSpellHyperlink || m_bSpellRest;
	}
	bool IsSpellInCheckedAll() const {
		return m_bSpellQuote && m_bSpellSingleQuotes && m_bSpellDoubleQuotes && m_bSpellComment && m_bSpellScript && m_bSpellInTag && m_bSpellHilite && m_bSpellHyperlink && m_bSpellRest;
	}
	int GetDefaultFontHeight( int nCharset, BOOL bUseCourierNew ) const;
	void FreeDefault();
};

// Command IDs
//

#define EEID_FILE_NEW                     4096
#define EEID_FILE_OPEN                    4097
#define EEID_FILE_CLOSE_OPEN              4098
#define EEID_FILE_SAVE                    4099
#define EEID_FILE_SAVE_AS                 4100
#define EEID_FILE_SAVE_ALL                4101
#define EEID_FILE_SAVE_ANSI               4102
#define EEID_FILE_SAVE_JIS                4103
#define EEID_FILE_SAVE_EUC                4104
#define EEID_SAVE_AS_CRLF                 4105
#define EEID_SAVE_AS_CR                   4106
#define EEID_SAVE_AS_LF                   4107
#define EEID_FILE_INSERT                  4108
#define EEID_FILE_RELOAD                  4109
#define EEID_FILE_RELOAD_ANSI             4110
#define EEID_FILE_RELOAD_JIS              4111
#define EEID_FILE_RELOAD_EUC              4112
#define EEID_READ_ONLY                    4113
#define EEID_FILE_PRINT                   4114
#define EEID_FILE_PRINT_DIRECT            4115
#define EEID_FILE_SAVE_EXIT               4116
#define EEID_APP_EXIT                     4117
#define EEID_SAVE_EXIT_ALL                4118
#define EEID_EXIT_ALL                     4119
#define EEID_APP_QUIT                     4120
#define EEID_NEW_TRAY_ICON                4121
#define EEID_TRAY_ICON_EXIT               4122
#define EEID_FILE_NEW_PASTE               4123
#define EEID_EDIT_UNDO                    4124
#define EEID_EDIT_REDO                    4125
#define EEID_EDIT_CUT                     4126
#define EEID_EDIT_COPY                    4127
#define EEID_EDIT_COPY_DESELECT           4128
#define EEID_EDIT_PASTE                   4129
#define EEID_EDIT_COPY_PREFIX             4130
#define EEID_EDIT_COPY_PREFIX_DESELECT    4131
#define EEID_PASTE_PREFIX                 4132
#define EEID_PASTE_RETURN                 4133
#define EEID_PASTE_PREFIX_RETURN          4134
#define EEID_DELETE                       4135
#define EEID_EDIT_SELECT_ALL              4136
#define EEID_INSERT_DATE                  4137
#define EEID_INSERT_DATE_TIME             4138
#define EEID_JUMP                         4139
#define EEID_EDIT_COPY_LINK               4140
#define EEID_LINK_OPEN                    4141
#define EEID_INSERT                       4142
#define EEID_INSERT_CR_WRAP               4143
#define EEID_DELETE_CR_WRAP               4144
#define EEID_INSERT_CR                    4145
#define EEID_INSERT_LF                    4146
#define EEID_TAG_JUMP                     4147
#define EEID_CONVERT                      4148
#define EEID_MAKE_UPPER                   4149
#define EEID_MAKE_LOWER                   4150
#define EEID_ZEN_TO_HAN                   4151
#define EEID_HAN_TO_ZEN                   4152
#define EEID_SELECT_CHAR                  4153
#define EEID_SELECT_LINE                  4154
#define EEID_SELECT_BOX                   4155
#define EEID_RIGHT                        4156
#define EEID_LEFT                         4157
#define EEID_RIGHT_WORD                   4158
#define EEID_LEFT_WORD                    4159
#define EEID_UP                           4160
#define EEID_DOWN                         4161
#define EEID_PAGEUP                       4162
#define EEID_PAGEDOWN                     4163
#define EEID_HOME                         4164
#define EEID_LOGICAL_HOME                 4165
#define EEID_END                          4166
#define EEID_LOGICAL_END                  4167
#define EEID_TOP                          4168
#define EEID_BOTTOM                       4169
#define EEID_SCROLL_UP                    4170
#define EEID_SCROLL_DOWN                  4171
#define EEID_SHIFT_RIGHT                  4172
#define EEID_SHIFT_LEFT                   4173
#define EEID_SHIFT_RIGHT_WORD             4174
#define EEID_SHIFT_LEFT_WORD              4175
#define EEID_SHIFT_UP                     4176
#define EEID_SHIFT_DOWN                   4177
#define EEID_SHIFT_PAGEUP                 4178
#define EEID_SHIFT_PAGEDOWN               4179
#define EEID_SHIFT_HOME                   4180
#define EEID_SHIFT_LOGICAL_HOME           4181
#define EEID_SHIFT_END                    4182
#define EEID_SHIFT_LOGICAL_END            4183
#define EEID_SHIFT_TOP                    4184
#define EEID_SHIFT_BOTTOM                 4185
#define EEID_BACK                         4186
#define EEID_ESCAPE                       4187
#define EEID_TAB                          4188
#define EEID_SHIFT_TAB                    4189
#define EEID_DELETE_LINE                  4190
#define EEID_DELETE_RIGHT_LINE            4191
#define EEID_EDIT_COPY_LINE               4192
#define EEID_EDIT_CUT_LINE                4193
#define EEID_DELETE_WORD                  4194
#define EEID_LINE_OPEN_ABOVE              4195
#define EEID_LINE_OPEN_BELOW              4196
#define EEID_INSERT_CONTROL               4197
#define EEID_TOGGLE_IME                   4198
#define EEID_RECONVERT                    4199
#define EEID_EDIT_FIND                    4200
#define EEID_EDIT_REPLACE                 4201
#define EEID_EDIT_REPEAT                  4202
#define EEID_EDIT_REPEAT_BACK             4203
#define EEID_FIND_NEXT_WORD               4204
#define EEID_FIND_PREV_WORD               4205
#define EEID_ERASE_FIND_HILITE            4206
#define EEID_GREP                         4207
#define EEID_WRAP_NONE                    4208
#define EEID_WRAP_BY_CHAR                 4209
#define EEID_WRAP_BY_WINDOW               4210
#define EEID_VIEW_STATUS_BAR              4212
#define EEID_WATCH_CHAR_CODE              4213
#define EEID_NEXT_PANE                    4214
#define EEID_PREV_PANE                    4215
#define EEID_QUICK_MACRO_RECORD           4216
#define EEID_QUICK_MACRO_RUN              4217
#define EEID_FONT                         4218
#define EEID_CUSTOMIZE                    4219
#define EEID_CONFIG_POPUP                 4220
#define EEID_CONFIG                       4221
#define EEID_COMMON_SETTINGS              4222
#define EEID_FILE_ASSOCIATE               4223
#define EEID_CUSTOMIZE_TOOLBAR            4224
#define EEID_CUSTOMIZE_PLUG_INS           4238
#define EEID_WINDOW_ALWAYS_TOP            4239
#define EEID_WINDOW_SPLIT                 4240
#define EEID_WINDOW_CASCADE               4241
#define EEID_WINDOW_TILE_HORZ             4242
#define EEID_WINDOW_TILE_VERT             4243
#define EEID_WINDOW_MINIMIZE_ALL          4244
#define EEID_NEXT_WINDOW                  4245
#define EEID_PREV_WINDOW                  4246
#define EEID_HELP_FINDER                  4247
#define EEID_HELP_REGIST                  4248
#define EEID_WEB_HOME                     4249
#define EEID_APP_ABOUT                    4250
#define EEID_SELECT_WORD                  4251
#define EEID_FILE_SAVE_RENAME             4252
#define EEID_TAB_TO_SPACE                 4253
#define EEID_FILE_SAVE_UNICODE            4254
#define EEID_FILE_SAVE_UTF8               4255
#define EEID_FILE_SAVE_UTF7               4256
#define EEID_FILE_RELOAD_UNICODE          4257
#define EEID_FILE_RELOAD_UTF8             4258
#define EEID_FILE_RELOAD_UTF7             4259
#define EEID_FILE_SAVE_UNICODE_BIGENDIAN  4260
#define EEID_FILE_RELOAD_UNICODE_BIGENDIAN 4261
#define EEID_EDIT_PASTE_ANSI              4262
#define EEID_FILE_RELOAD_932              4263
#define EEID_DEFINE_CODE_PAGE             4264
#define EEID_FILE_SAVE_932                4265
#define EEID_CUSTOMIZE_MENU               4266
#define EEID_ALL_COMMANDS                 4267
#define EEID_NEXT_LOGICAL_LINE            4268
#define EEID_PREV_LOGICAL_LINE            4269
#define EEID_ALL_PROP                     4270
#define EEID_NEW_PASTE_PREFIX             4271
#define EEID_NEW_PASTE_PREFIX_RETURN      4272
#define EEID_CUSTOMIZE_TRAY               4273
#define EEID_INSERT_CR_LF                 4274
#define EEID_DELETE_RIGHT_WORD            4275
#define EEID_NEXT_PAREN                   4276
#define EEID_SHIFT_NEXT_PAREN             4277
#define EEID_TRIM_RIGHT                   4278
#define EEID_FILE_RELOAD_DETECT_ALL       4279
#define EEID_DELETE_LEFT_WORD             4280
#define EEID_NEW_CONFIG_POPUP             4281
#define EEID_FONT_POPUP                   4282
#define EEID_RELOAD_POPUP                 4283
#define EEID_DELETE_PANES                 4284
#define EEID_SHOW_PLUGINS_BAR             4285
#define EEID_PRINT_PREVIEW                4286
#define EEID_WINDOW_TOP                   4292
#define EEID_WINDOW_BOTTOM                4293
#define EEID_WINDOW_RIGHT                 4294
#define EEID_WINDOW_LEFT                  4295
#define EEID_HOME_TEXT                    4296
#define EEID_SHIFT_HOME_TEXT              4297
#define EEID_KEYBOARD_MAP                 4298
#define EEID_WINDOW_SPLIT_HORZ            4299
#define EEID_WINDOW_SPLIT_VERT            4300
#define EEID_CONTEXT_MENU                 4301
#define EEID_DELETE_LEFT_LINE             4302
#define EEID_INSERT_GRAVE                 4303
#define EEID_INSERT_ACUTE                 4304
#define EEID_INSERT_CIRCUMFLEX            4305
#define EEID_INSERT_TILDE                 4306
#define EEID_INSERT_DIAERESIS             4307
#define EEID_INSERT_RING_ABOVE            4308
#define EEID_INSERT_LIGATURE              4309
#define EEID_INSERT_CEDILLA               4310
#define EEID_INSERT_STROKE                4311
#define EEID_INSERT_INVERTED_QUESTION     4312
#define EEID_INSERT_INVERTED_EXCLAMATION  4313
#define EEID_INSERT_COPYRIGHT             4314
#define EEID_INSERT_REGISTERED            4315
#define EEID_INSERT_TRADEMARK             4316
#define EEID_INSERT_EURO                  4317
#define EEID_WRAP_BY_PAPER                4318
#define EEID_SHOW_TOOLS_BAR               4319
#define EEID_BOOKMARK_TOGGLE              4320
#define EEID_BOOKMARK_NEXT                4321
#define EEID_BOOKMARK_PREV                4322
#define EEID_BOOKMARK_CLEAR               4323
#define EEID_CUSTOMIZE_TOOLS              4324
#define EEID_RETRIEVE_FIND_TEXT           4325
#define EEID_COPY_FILE_PATH               4326
#define EEID_COPY_FILE_DIR                4327
#define EEID_DUPLICATE_LINE               4328
#define EEID_LOAD_WORKSPACE               4329
#define EEID_SAVE_WORKSPACE               4330
#define EEID_SAVE_WORKSPACE_EXIT_ALL      4331
#define EEID_SAVE_WORKSPACE_QUIT_ALL      4332
#define EEID_LOGICAL_HOME_TEXT            4333
#define EEID_SHIFT_LOGICAL_HOME_TEXT      4334
#define EEID_WINDOW_SPLIT_HORZ_FIX        4335
#define EEID_WINDOW_SPLIT_VERT_FIX        4336
//#define EEID_SHOW_WINDOWS_BAR             4337
#define EEID_SHOW_BAR_TITLE               4340
#define EEID_LOCK_TOOLBARS                4341
#define EEID_WINDOW_COMBINE               4342
#define EEID_WINDOW_ALWAYS_TOP_ON         4343
#define EEID_WINDOW_ALWAYS_TOP_OFF        4344
#define EEID_MOVE_LAST_EDIT               4345
#define EEID_MACRO_SAVE                   4346
#define EEID_MACRO_SELECT                 4347
#define EEID_MACRO_EDIT                   4348
#define EEID_MACRO_SELECT_THIS            4349
#define EEID_CUSTOMIZE_MACRO              4350
#define EEID_BOOKMARK_NEXT_WITHIN         4351
#define EEID_BOOKMARK_PREV_WITHIN         4352
#define EEID_BOOKMARK_SET                 4353
#define EEID_BOOKMARK_RESET               4354
#define EEID_SPACE_TO_TAB                 4355
#define EEID_TABIFY                       4356
#define EEID_UNTABIFY                     4357
#define EEID_INDENT                       4358
#define EEID_UNINDENT                     4359
#define EEID_MACRO_HELP                   4360
#define EEID_MACRO_HELP_WORD              4361
#define EEID_REPLACE_IN_FILES             4362
#define EEID_QUIT_ALL                     4363
#define EEID_MACRO_RUN_OPTIONS            4364
#define EEID_INSERT_CARON                 4369
#define EEID_VIEW_MARKS                   4370
#define EEID_EDIT_COMMENT                 4371
#define EEID_EDIT_UNCOMMENT               4372
#define EEID_INCREASE_FONT_SIZE           4373
#define EEID_DECREASE_FONT_SIZE           4374
#define EEID_FIND_NEXT_UNICODE            4375
#define EEID_FIND_PREV_UNICODE            4376
#define EEID_ERASE_UNICODE_HILITE         4377
#define EEID_JOIN_LINES                   4378
#define EEID_SPLIT_LINES                  4379
#define EEID_IMPORT_EXPORT                4380
#define EEID_CAPITALIZE                   4381
#define EEID_WINDOW_MOVE_NEXT             4382
#define EEID_WINDOW_MOVE_PREV             4383
#define EEID_CLOSE_ALL_OTHERS             4384
#define EEID_WINDOW_SPLIT_HORZ_TOGGLE     4385
#define EEID_WINDOW_SPLIT_VERT_TOGGLE     4386
#define EEID_GROUP_CLOSE_ALL              4387
#define EEID_GROUP_CLOSE_OTHERS           4388
#define EEID_GROUP_CLOSE_LEFT             4389
#define EEID_GROUP_CLOSE_RIGHT            4390
#define EEID_NEW_GROUP                    4391
#define EEID_NEW_GROUP_MINIMIZE           4392
#define EEID_NEW_GROUP_CASCADE            4393
#define EEID_NEW_GROUP_HORZ               4394
#define EEID_NEW_GROUP_VERT               4395
#define EEID_MOVE_PREV_GROUP              4396
#define EEID_MOVE_NEXT_GROUP              4397
#define EEID_SORT_FILE_NAME               4398
#define EEID_SORT_TYPE                    4399
#define EEID_SORT_MODIFIED                4400
#define EEID_SORT_ZORDER                  4401
#define EEID_SORT_ASCENDING               4402
#define EEID_SORT_DESCENDING              4403
#define EEID_AUTO_SORT                    4404
#define EEID_RESTORE_POS                  4406
#define EEID_WINDOW_COMBINE_ON            4407
#define EEID_WINDOW_COMBINE_OFF           4408
#define EEID_ACTIVE_PANE                  4409
#define EEID_OUTLINE_COLLAPSE_ALL         4410
#define EEID_OUTLINE_EXPAND_ALL           4411
#define EEID_OUTLINE_TOGGLE_LINE          4412
#define EEID_OUTLINE_COLLAPSE_LINE        4413
#define EEID_OUTLINE_EXPAND_LINE          4414
#define EEID_OUTLINE_NEXT_NODE            4415
#define EEID_OUTLINE_PREV_NODE            4416
#define EEID_SHIFT_NEXT_NODE              4417
#define EEID_SHIFT_PREV_NODE              4418
#define EEID_RESTORE_DELETED              4419
#define EEID_VIEW_OUTPUT                  4420
#define EEID_SHOW_MACROS_BAR              4421
#define EEID_REFRESH_TOOLBARS             4422
//#define EEID_RECORD_MOUSE                 4423
#define EEID_RECORD_NO_MOUSE              4424
#define EEID_FOCUS_LEFT_BAR               4425
#define EEID_FOCUS_TOP_BAR                4426
#define EEID_FOCUS_RIGHT_BAR              4427
#define EEID_FOCUS_BOTTOM_BAR             4428
#define EEID_USER_MENU1                   4429
#define EEID_USER_MENU2                   4430
#define EEID_USER_MENU3                   4431
#define EEID_USER_MENU4                   4432
#define EEID_USER_MENU5                   4433
#define EEID_USER_MENU6                   4434
#define EEID_USER_MENU7                   4435
#define EEID_USER_MENU8                   4436
#define EEID_SELECT_LOGICAL_LINE          4437
#define EEID_FILE_RELOAD_BINARY           4438
#define EEID_FILE_RELOAD_HEX              4439
#define EEID_FILE_SAVE_BINARY             4440
#define EEID_FILE_SAVE_HEX                4441
#define EEID_JUMP_NEXT                    4442
#define EEID_JUMP_PREV                    4443
#define EEID_EDIT_CUT_SEL                 4444
#define EEID_EDIT_COPY_SEL                4445
#define EEID_RETRIEVE_REPLACE_TEXT        4446
#define EEID_REPLACE_NEXT                 4447
#define EEID_VIEW_FUNCTION_BAR            4448
#define EEID_LARGE_FILE_BAR               4449
#define EEID_ERASE_WORKSPACE              4450
#define EEID_TERMINATE_TOOL               4451
#define EEID_OUTPUT_CLEAR                 4452
#define EEID_FULL_SCREEN                  4453
#define EEID_PASTE_HISTORY                4454
#define EEID_CUSTOMIZE_JUMP_LIST          4455
#define EEID_NARROWING_TOGGLE             4456
#define EEID_NARROWING_ON                 4457
#define EEID_NARROWING_OFF                4458
#define EEID_MODE_CSV                     4459
#define EEID_ADJUST_COLUMN                4460
#define EEID_SELECT_COLUMN                4461
#define EEID_ACTIVATE_OR_NEW			  4462
#define EEID_MODE_TSV                     4471
#define EEID_MODE_NORMAL                  4472
#define EEID_VERTICAL_MODE                4473
#define EEID_WINDOW_SCROLL_LEFT           4474
#define EEID_WINDOW_SCROLL_RIGHT          4475
#define EEID_MODE_DSV                     4476
#define EEID_SORT_TEXT_A                  4477
#define EEID_SORT_TEXT_D                  4478
#define EEID_SORT_NUM_A                   4479
#define EEID_SORT_NUM_D                   4480
#define EEID_CHECK_UPDATES                4481
#define EEID_CUSTOMIZE_UPDATE_CHECKER     4482

// v10 commands
#define EEID_SAVE_UTF16LE_SIGN            4483
#define EEID_SAVE_UTF16LE_NOSIGN          4484
#define EEID_SAVE_UTF16BE_SIGN            4485
#define EEID_SAVE_UTF16BE_NOSIGN          4486
#define EEID_SAVE_UTF8_SIGN               4487
#define EEID_SAVE_UTF8_NOSIGN             4488
#define EEID_SELECT_CELL                  4489
#define EEID_NEXT_CELL                    4490
#define EEID_PREV_CELL                    4491
#define EEID_COMPARE_DIRECT               4492
#define EEID_COMPARE_OPTIONS              4493
#define EEID_COMPARE_RESCAN               4494
#define EEID_SYNC_SCROLL_DIRECT           4495
#define EEID_SYNC_SCROLL_OPTIONS          4496
#define EEID_COMPARE_RESET                4497
#define EEID_IGNORE_LEAD_SPACE            4498
#define EEID_IGNORE_TRAIL_SPACE           4499
#define EEID_IGNORE_EMBEDDED_SPACE        4500
#define EEID_IGNORE_CASES                 4501
#define EEID_IGNORE_RETURNS               4502
#define EEID_IGNORE_COMMENT               4503
#define EEID_IGNORE_ENCODING              4504
#define EEID_SYNC_VERT                    4505
#define EEID_SYNC_HORZ                    4506
#define EEID_SYNC_CARET                   4507
#define EEID_COMPARE_SAVE_OPTIONS         4508
#define EEID_COMPARE_PREV                 4509
#define EEID_COMPARE_NEXT                 4510
#define EEID_SPELL_ADD_DIC                4511
#define EEID_SPELL_TOGGLE                 4512
#define EEID_SPELL_QUOTE                  4513
#define EEID_SPELL_SINGLE_QUOTES          4514
#define EEID_SPELL_DOUBLE_QUOTES          4515
#define EEID_SPELL_COMMENTS               4516
#define EEID_SPELL_SCRIPT                 4517
#define EEID_SPELL_TAGS                   4518
#define EEID_SPELL_HILITE                 4519
#define EEID_SPELL_HYPERLINK              4520
#define EEID_SPELL_REST                   4521
#define EEID_SPELL_ALL                    4522
#define EEID_SYNC_HORZ_SCROLL_SPLIT       4523
#define EEID_SYNC_VERT_SCROLL_SPLIT       4524
#define EEID_ENCODE_HTML_CHAR_REF         4525
#define EEID_DECODE_HTML_CHAR_REF         4526
#define EEID_ENCODE_UCN                   4527
#define EEID_DECODE_UCN                   4528
#define EEID_VIEW_LINE_NUMBERS            4530
#define EEID_VIEW_RULER                   4531
#define EEID_VIEW_RETURN                  4532
#define EEID_VIEW_EOF                     4533
#define EEID_VIEW_TAB                     4534
#define EEID_VIEW_SPACE                   4535
#define EEID_VIEW_WIDE_SPACE              4536
#define EEID_VIEW_CR_LF_SEPARATE          4537
#define EEID_VIEW_CONTROL                 4538
#define EEID_VIEW_INDENT_GUIDES           4539
#define EEID_TOGGLE_AUTO_INDENT           4540
#define EEID_TOGGLE_SPACES_TAB            4541
#define EEID_TOGGLE_WRAP_INDENT           4542
#define EEID_RESTORE_COMBINED_POS         4543
#define EEID_NEXT_ZORDER_DOC              4544
#define EEID_PREV_ZORDER_DOC              4545
#define EEID_SYNC_RESTORE_POS             4546
#define EEID_RIGHT_DOC                    4547
#define EEID_LEFT_DOC                     4548
#define EEID_TOGGLE_OUTPUT_SHORTCUTS      4549
#define EEID_TAB_COLUMN_POPUP             4550
#define EEID_INDENT_COLUMN_POPUP          4551
#define EEID_NEXT_PANE_OR_BAR             4552
#define EEID_PREV_PANE_OR_BAR             4553
#define EEID_SPELL_NEXT                   4554
#define EEID_SPELL_PREV                   4555
#define EEID_COMPARE_PREV_LINE            4556
#define EEID_COMPARE_NEXT_LINE            4557
#define EEID_NUMBERING                    4558

// v11 commands
#define EEID_SHOW_FIND_BAR                4559
#define EEID_ADD_TO_MARKERS               4560
#define EEID_SHOW_MARKERS_BAR             4561
#define EEID_CUSTOMIZE_MARKERS            4562
#define EEID_ENCODE_HTML_CHAR_ENTITY_REF  4563
#define EEID_DELETE_DUPLICATE             4564
#define EEID_FOCUS_FIND_BAR               4565
#define EEID_FINDBAR_BROWSE_EXP_F         4567
#define EEID_FINDBAR_BROWSE_EXP_R		  4568
#define EEID_FINDBAR_FIND_PREV            4569
#define EEID_FINDBAR_FIND_NEXT			  4570
#define EEID_FINDBAR_INCREMENTAL          4571
#define EEID_FINDBAR_OPEN_DOC             4572
#define EEID_FINDBAR_CASE                 4573
#define EEID_FINDBAR_REG_EXP              4574
#define EEID_FINDBAR_ESCAPE               4575
#define EEID_FINDBAR_ONLY_WORD            4576
#define EEID_FINDBAR_AROUND               4577
#define EEID_FINDBAR_COUNT                4578
#define EEID_FINDBAR_REPLACE_DLG          4579
#define EEID_FINDBAR_SEL_ONLY             4580
#define EEID_FINDBAR_REPLACE_NEXT         4581
#define EEID_FINDBAR_REPLACE_ALL          4582
#define EEID_MOST_RECENT_CLOSED_FILE      4583
#define EEID_CLOSE_FIND_BAR               4584
#define EEID_MARKER_ENABLE_ALL            4585
#define EEID_MARKER_DISABLE_ALL           4586
#define EEID_MARKER_DELETE_ALL            4587

// v12 commands
#define EEID_BOOKMARK_INVERT              4588
#define EEID_BOOKMARK_DELETE              4589
#define EEID_BOOKMARK_EXTRACT             4590
#define EEID_ADD_REMOVE_MARKER            4591
#define EEID_BOOKMARK_GROUP_EXTRACT       4592
#define EEID_COMPARE_BOOKMARK             4593
#define EEID_BOOKMARK_GROUP_CLEAR         4594
#define EEID_BOOKMARK_GROUP_INVERT        4595
#define EEID_BOOKMARK_GROUP_DELETE        4596
#define EEID_CARET_BACK                   4597
#define EEID_CARET_FORWARD                4598
#define EEID_SHOW_LAST_MESSAGE            4600
#define EEID_NEXT_TAG                     4601
#define EEID_SHIFT_NEXT_TAG               4602

// v13 commands
#define EEID_SELECT_ALL_OCCURRENCES       4603
#define EEID_ADD_NEXT_OCCURRENCE          4604
#define EEID_ADD_NEXT2_OCCURRENCE         4605
#define EEID_SPLIT_TO_FILES               4606
#define EEID_COMBINE_FILES                4607
#define EEID_SEARCH_ALL_COMMANDS          4608
#define EEID_FILE_SAVE_ALL_AS             3843
#define EEID_HELP_DOWNGRADE               3844
#define EEID_HELP_UPGRADE                 3845
#define EEID_REPEAT_LAST_COMMAND          3846
#define EEID_CONFIG_ASSOCIATE             3847
#define EEID_SELECT_BEGIN_LINES           3848
#define EEID_SELECT_END_LINES             3849
#define EEID_SWITCH_START_END_SELECT      3850
#define EEID_BOOKMARK_SELECT              3851
#define EEID_BOOKMARK_CUT                 3852
#define EEID_BOOKMARK_COPY                3853

// v14 commands
#define EEID_DECODE_PERCENT               3854
#define EEID_ENCODE_PERCENT               3855
#define EEID_DECODE_PERCENT_UTF8          3856
#define EEID_ENCODE_PERCENT_UTF8          3857
#define EEID_MOVE_LINE_UP                 3858
#define EEID_MOVE_LINE_DOWN               3859

// v14.1 commands
#define EEID_RESET_ALL                    3860

// v14.2 commands
#define EEID_INSERT_MACRON                3861
#define EEID_ADD_REMOVE_GUIDE             3862
#define EEID_VIEW_USER_DEFINED_GUIDES     3863

// v14.3 commands
#define EEID_SCROLL_TOP                   3864
#define EEID_SCROLL_BOTTOM                3865
#define EEID_SCROLL_PAGE_UP               3866
#define EEID_SCROLL_PAGE_DOWN             3867
#define EEID_SCROLL_PAGE_LEFT             3868
#define EEID_SCROLL_PAGE_RIGHT            3869
#define EEID_SCROLL_LEFT_EDGE             3870
#define EEID_SCROLL_RIGHT_EDGE            3871

// v14.4 commands
#define EEID_OUTLINE_BAR                  3872
#define EEID_OUTLINE_GUIDE                3873
#define EEID_OUTLINE_BAR_GUIDE            3874
#define EEID_OUTLINE_POPUP	              3875
#define EEID_RESET_FONT_SIZE              3876
#define EEID_SET_DEFAULT_FONT_SIZE        3877
#define EEID_INSERT_TAB                   3878

// v14.5 command
#define EEID_OUTLINE_SYNC_BAR_TO_GUIDE    3879

// v14.6 commands
#define EEID_HEADING_TOGGLE               3880
#define EEID_HEADING_SET                  3881
#define EEID_HEADING_RESET                3882
#define EEID_CONVERT_TO_FIXED_WIDTH       3883
#define EEID_ADD_REMOVE_SEPARATOR         3884
#define EEID_AUTO_ADD_SEPARATORS          3885
#define EEID_REMOVE_ALL_SEPARATORS        3886
#define EEID_INSERT_COLUMN                3887
#define EEID_ADD_COLUMN                   3888
#define EEID_VERTICAL_SELECTION           3889
#define EEID_SHOW_SV_BAR                  3890
#define EEID_SV_SEP_POPUP                 3893
#define EEID_HEADING_1                    3894
#define EEID_HEADING_2                    3895
#define EEID_HEADING_3                    3896
#define EEID_HEADING_4                    3897
#define EEID_HEADING_POPUP                3898
#define EEID_SV_POPUP                     3899
#define EEID_READ_ONLY_HEADINGS           3900
#define EEID_ADJUST_COLUMN_VISIBLE        3901
#define EEID_REMOVE_UNNECESSARY_QUOTES    3902
#define EEID_SORT_MULTI                   3903
#define EEID_FILTERBAR_BROWSE_EXP_F       3904
#define EEID_FILTERBAR_REFRESH            3905
#define EEID_FILTERBAR_INCREMENTAL        3906
#define EEID_FILTERBAR_CASE               3907
#define EEID_FILTERBAR_REG_EXP            3908
#define EEID_FILTERBAR_ESCAPE             3909
#define EEID_FILTERBAR_ONLY_WORD          3910
#define EEID_SHOW_FILTER_BAR              3911
#define EEID_FOCUS_FILTER_BAR             3912
#define EEID_CLOSE_FILTER_BAR             3913
#define EEID_FILTERBAR_ABORT              3914
#define EEID_FILTERBAR_LIMIT              3915

// v14.7 commands
#define EEID_FILTERBAR_NEGATIVE           3916
#define EEID_SORT_LENGTH_A                3917
#define EEID_SORT_LENGTH_D                3918
#define EEID_FILTERBAR_ADVANCED           3919

// v14.8
#define EEID_DELETE_DUPLICATE_ADVANCED    3920
#define EEID_JOIN_CSV                     3921

// v14.9
#define EEID_REMOVE_EMBEDDED_NL           3922
//#define EEID_FINDBAR_EMBEDDED_NL		  3923  // obsolete

// v15.0
#define EEID_WORKSPACE_OPEN               3924
#define EEID_WORKSPACE_SAVE_AS            3925
#define EEID_WORKSPACE_SAVE_CURRENT       3926
#define EEID_FILTERBAR_BOOKMARK           3927
#define EEID_FILTERBAR_EXTRACT            3928
#define EEID_FILTER_WORD                  3929

// v15.1
#define EEID_EXTRACT_COLUMNS              3930
#define EEID_SELECT_COLUMN_WITH_HEADINGS  3931

// v15.2
#define EEID_HELP_INTERNET                3932
#define EEID_HELP_LOCAL                   3933

// v15.3
#define EEID_SAVE_CLOSE_DESKTOP           3934
#define EEID_CLOSE_DESKTOP                3935
#define EEID_QUIT_DESKTOP                 3936
#define EEID_SAVE_WORKSPACE_CLOSE_DESKTOP 3937
#define EEID_SAVE_WORKSPACE_QUIT_DESKTOP  3938

// v15.4
#define EEID_DECODE_BASE64                3939
#define EEID_ENCODE_BASE64                3940
#define EEID_DECODE_BASE64_UTF8           3941
#define EEID_ENCODE_BASE64_UTF8           3942
#define EEID_DECODE_BASE64_BINARY         3943
#define EEID_ENCODE_BASE64_BINARY         3944
#define EEID_SORT_WORDS_A                 3945
#define EEID_SORT_WORDS_D                 3946
#define EEID_CLEAR_VISIT_HISTORY          3947

// v15.5
#define EEID_START_WINDOW                 3948
#define EEID_TOGGLE_OUTPUT_WRAP           3949

// v15.6
#define EEID_UPDATE_CHANNEL               3950
#define EEID_QL_COMMANDS                  3951
#define EEID_QL_OPTIONS                   3952
#define EEID_QL_SYMBOLS                   3953
#define EEID_CUSTOMIZE_MACRO_MY_MACROS    3954
#define EEID_CUSTOMIZE_MACRO_OPTIONS      3955
#define EEID_CUSTOMIZE_MARKERS_LIST       3956
#define EEID_CUSTOMIZE_MARKERS_AUTO       3957
#define EEID_CUSTOMIZE_MARKERS_OPTIONS    3958

// v15.7
#define EEID_FINDBAR_ADVANCED             3923

// v15.8
#define EEID_CSV_CELL_MODE                3959
#define EEID_CSV_EDIT_CELL                3960
#define EEID_DELETE_COMPLETE              3961

// v15.9
#define EEID_CSV_CONVERTER                3891
#define EEID_DELETE_COLUMN                3962
#define EEID_CUT_COLUMN                   3963
#define EEID_COPY_COLUMN                  3964
#define EEID_INSERT_COLUMN_RIGHT          3965

// v16.0
#define EEID_ADD_QUOTES                   3966

// v16.1
#define EEID_SHOW_CELL_BAR                3967
#define EEID_CELL_BAR_OPTIONS             3968
#define EEID_CELL_BAR_AUTO_SHOW           3969
#define EEID_CELL_BAR_AUTO_FOCUS          3970
#define EEID_CELL_BAR_AUTO_HEIGHT         3971

// v16.2
#define EEID_SORT_DATE_A                  3972
#define EEID_SORT_DATE_D                  3973

// v16.3
#define EEID_FILTER_OUT_WORD              3974
#define EEID_MINIMAP_TOGGLE               3975
#define EEID_MINIMAP_ZOOM_IN              3976
#define EEID_MINIMAP_ZOOM_OUT             3977
#define EEID_MINIMAP_ENTIRE_MAP           3978

// v16.4
#define EEID_AUTO_COPY                    3979

// v16.8
#define EEID_UNDO_ALL                     3980
#define EEID_REDO_ALL                     3981
#define EEID_UNDO_HISTORY                 3982

// v16.9
#define EEID_FILTER_COLUMN                3983

// v17.0
#define EEID_DELETE_OLD_SETTINGS          3984

// v17.1
#define EEID_HEADER_TOGGLE                3985
#define EEID_HEADER_NUM                   3986
#define EEID_HEADER_ALPHA                 3987
#define EEID_HEADER_ZERO_BASE             3988

// v17.2
#define EEID_SCROLL_MARKS_TOGGLE          3989
#define EEID_CSV_VALIDATE                 3990
#define EEID_FLASH_FILL                   3991
#define EEID_AUTO_FILL                    3992
#define EEID_MAKE_COLUMNS_SAME			  3993

// v17.3
#define EEID_MOVE_COLUMN_RIGHT            3994
#define EEID_MOVE_COLUMN_LEFT             3995

// v17.7
#define EEID_COMPARE_GENERATE_REPORT      3996
#define EEID_USE_DIRECT_WRITE             3997

// v17.9
#define EEID_DUPLICATE_COLUMN             3998

// v18.2
#define EEID_BOOKMARK_NEXT_AROUND         3999
#define EEID_BOOKMARK_PREV_AROUND         4000
#define EEID_SORT_OCCURRENCE_A            4001
#define EEID_SORT_OCCURRENCE_D            4002

// v18.3
#define EEID_SORT_RANDOM                  4003
#define EEID_FILTERBAR_BOOKMARKED_ONLY    4004
#define EEID_FILTERBAR_UNBOOKMARKED_ONLY  4005
#define EEID_FILTERBAR_MATCH_NL			  4006
#define EEID_FILTERBAR_CR_ONLY			  4007
#define EEID_FILTERBAR_LF_ONLY			  4008
#define EEID_FILTERBAR_CR_LF			  4009
#define EEID_FILTERBAR_NL_OTHERS	      4010

// v18.4
#define EEID_CLEAR_SAVED_MARKERS          4011
#define EEID_FILTER_OUT_COLUMN            4012
#define EEID_FILTERBAR_NUMBER_RANGE       4013
#define EEID_FINDBAR_NUMBER_RANGE         4014
#define EEID_SEL_TRIM_LEFT                4015
#define EEID_SEL_TRIM_RIGHT               4016

// v18.5
#define EEID_RIGHT_EDGE                   4017
#define EEID_LEFT_EDGE                    4018
#define EEID_TOP_EDGE                     4019
#define EEID_BOTTOM_EDGE                  4020
#define EEID_SHIFT_RIGHT_EDGE             4021
#define EEID_SHIFT_LEFT_EDGE              4022
#define EEID_SHIFT_TOP_EDGE               4023
#define EEID_SHIFT_BOTTOM_EDGE            4024
#define EEID_BOX_EXTEND_RIGHT             4025
#define EEID_BOX_EXTEND_LEFT              4026
#define EEID_BOX_EXTEND_UP	              4027
#define EEID_BOX_EXTEND_DOWN              4028

// v18.6
#define EEID_REMOVE_EMPTY_LINES           4029
#define EEID_CANCEL_TOP_SEL               4030
#define EEID_CANCEL_BOTTOM_SEL            4031
#define EEID_FILTERBAR_WHOLE_STRING       4032

// v18.7
#define EEID_CLEAR_CONTENTS               4033

// v18.9
#define EEID_SORT_IPV4_A                  4034
#define EEID_SORT_IPV4_D                  4035
#define EEID_SORT_IPV6_A                  4036
#define EEID_SORT_IPV6_D                  4037

// v19.0
#define EEID_TOGGLE_VALIDATION_BAR        4038
#define EEID_SORT_REVERSE                 4039

// v19.2
#define EEID_VIEW_ALL_MARKS               4040

// v19.5
#define EEID_EXTRACT_FREQUENT             4041
#define EEID_MARKER_COUNT_MATCHES         4042
#define EEID_MARKER_CLEAR_COUNT           4043

// v19.6
#define EEID_MINIMAP_HOVER                4044
#define EEID_CLIPBOARD_HISTORY            4045

// v19.7
#define EEID_MOVE_COLUMN                  4046
#define EEID_COMBINE_COLUMNS              4047

// v19.8
#define EEID_COMPARE_JUMP_TO_OTHER        4048
#define EEID_FIND_LONGEST                 4049
#define EEID_FIND_SHORTEST                4050
#define EEID_ADVANCED_OPEN                4051
#define EEID_RESET_COLUMN_WIDTH           4052
#define EEID_UNICODE_NORM_FC              4053
#define EEID_UNICODE_NORM_FD              4054
#define EEID_UNICODE_NORM_FKC             4055
#define EEID_UNICODE_NORM_FKD             4056

// v19.9
#define EEID_SPLIT_COLUMN                 4057
#define EEID_SEND_FEEDBACK                4058
#define EEID_WRITE_REVIEW                 4059

// other commands
#define EEID_FILE_MRU_FILE1               4609  // to EEID_FILE_MRU_FILE1 + 63
#define EEID_MRU_FONT1                    4736  // to EEID_MRU_FONT1 + 63
#define EEID_RECENT_CLOSED_FILE1          4800  // to EEID_RECENT_CLOSED_FILE1 + 63
#define EEID_FILE_MRU_INSERT1             4864  // to EEID_FILE_MRU_INSER1 + 63
#define EEID_FILE_MRU_FOLDER1             4992  // to EEID_FILE_MRU_FOLDER1 + 63
#define EEID_SELECT_CONFIG                5120  // to EEID_SELECT_CONFIG + 255
#define EEID_WINDOW_MENU                  5376  // to EEID_WINDOW_MENU + 255
#define EEID_PLUG_IN1                     5632  // to EEID_PLUG_IN1 + 255
#define EEID_FILE_RELOAD_DEFINED          6656  // to EEID_FILE_RELOAD_DEFINED + 255
#define EEID_FILE_NEW_CONFIG              7168  // to EEID_FILE_NEW_CONFIG + 255
#define EEID_FILE_SAVE_DEFINED            7680  // to EEID_FILE_SAVE_DEFINED + 255
#define EEID_TOOL1                        8192  // to EEID_TOOL1 + 255
#define EEID_SPELL_SUGGEST				  8768  // to EEID_SPELL_SUGGEST + 31
#define EEID_PASTE_RECENT                 9120  // to EEID_PASTE_RECENT + 31
#define EEID_MACRO1                       9216  // to EEID_MACRO1 + 1023
#define EEID_CUSTOM_REBAR1                21504 // to EEID_CUSTOM_REBAR1 + 255
#define EEID_SELECT_DICTIONARY			  22016 // to EEID_SELECT_DICTIONARY + 255
#define EEID_MARKER1                      22272 // to EEID_MARKER1 + 255
#define EEID_SV_MODE					  22528 // to EEID_SV_MODE + 63
#define EEID_CONVERT_TO_SV                22656 // to EEID_CONVERT_TO_SV + 63
#define EEID_WORKSPACE_RECENT_FILE1       22784 // to EEID_WORKSPACE_RECENT_FILE1 + 63
#define EEID_UNDO_RECENT				  22848 // to EEID_UNDO_RECENT + 63
#define EEID_REDO_RECENT				  22912 // to EEID_REDO_RECENT + 63

#define EEID_CHARSET_DEFAULT              8704
#define EEID_CHARSET_ARABIC               8705
#define EEID_CHARSET_BALTIC               8706
#define EEID_CHARSET_CENTRAL_EUROPE       8707
#define EEID_CHARSET_CHINESE_SIMPLIFIED   8708
#define EEID_CHARSET_CHINESE_TRADITIONAL  8709
#define EEID_CHARSET_CYRILLIC             8710
#define EEID_CHARSET_GREEK                8711
#define EEID_CHARSET_HEBREW               8712
#define EEID_CHARSET_JAPANESE             8713
#define EEID_CHARSET_KOREAN               8714
#define EEID_CHARSET_THAI                 8715
#define EEID_CHARSET_TURKISH              8716
#define EEID_CHARSET_VIETNAMESE           8717
#define EEID_CHARSET_WESTERN_EUROPE       8718
#define EEID_CHARSET_OEM                  8719

#define EEID_OUTLINE_LEVEL_2              8832
#define EEID_OUTLINE_LEVEL_3              8833
#define EEID_OUTLINE_LEVEL_4              8834
#define EEID_OUTLINE_LEVEL_5              8835
#define EEID_OUTLINE_LEVEL_6              8836
#define EEID_OUTLINE_LEVEL_7              8837
#define EEID_OUTLINE_LEVEL_8              8838
#define EEID_OUTLINE_LEVEL_9              8839
#define EEID_OUTLINE_LEVEL_10             8840
#define EEID_OUTLINE_LEVEL_11             8841
#define EEID_OUTLINE_LEVEL_12             8842
#define EEID_OUTLINE_LEVEL_13             8843
#define EEID_OUTLINE_LEVEL_14             8844
#define EEID_OUTLINE_LEVEL_15             8845
#define EEID_OUTLINE_LEVEL_16             8846

#define EEID_PROPERTY_MARGIN              8960
#define EEID_PROPERTY_SCROLL              8961
#define EEID_PROPERTY_FILE                8962
#define EEID_PROPERTY_BACKUP              8963
#define EEID_PROPERTY_AUTO_SAVE           8964
#define EEID_PROPERTY_ASSOCIATE           8965
#define EEID_PROPERTY_KINSOKU             8966
#define EEID_PROPERTY_FACE                8967
#define EEID_PROPERTY_HILITE              8968
#define EEID_PROPERTY_COMMENT             8969
#define EEID_PROPERTY_SHOW                8970
#define EEID_PROPERTY_MARK                8971
#define EEID_PROPERTY_PRINT               8972
#define EEID_PROPERTY_LINK                8973
#define EEID_PROPERTY_KEYBOARD            8974
#define EEID_PROPERTY_SPELL               8975
#define EEID_PROPERTY_OUTLINE             8976
#define EEID_PROPERTY_INDENT              8977
#define EEID_PROPERTY_FILE_NEW            8978
#define EEID_PROPERTY_FILE_SAVE           8979
#define EEID_PROPERTY_VALIDATION          8980

#define EEID_CUSTOMIZE_FILE               9040
#define EEID_CUSTOMIZE_SEARCH             9041
#define EEID_CUSTOMIZE_HISTORY            9042
#define EEID_CUSTOMIZE_WINDOW             9043
#define EEID_CUSTOMIZE_TAB                9044
#define EEID_CUSTOMIZE_STATUS             9045
#define EEID_CUSTOMIZE_ADVANCED           9046
#define EEID_CUSTOMIZE_LANG               9047
#define EEID_CUSTOMIZE_SHORTCUT           9048
#define EEID_CUSTOMIZE_EDIT               9049
#define EEID_CUSTOMIZE_MARKS              9050
#define EEID_CUSTOMIZE_VIEW               9051
#define EEID_CUSTOMIZE_MOUSE              9052
#define EEID_CUSTOMIZE_SORT               9053
#define EEID_CUSTOMIZE_OUTLINE            9054
#define EEID_CUSTOMIZE_SV                 9055
#define EEID_CUSTOMIZE_FORMAT             9056
#define EEID_CUSTOMIZE_ACTIVE_STRING      9057
#define EEID_CUSTOMIZE_RENDERING          9058
#define EEID_CUSTOMIZE_WORKSPACE          9059
#define EEID_CUSTOMIZE_SYNC               9060
#define EEID_CUSTOMIZE_OPTIMIZATION       9061
#define EEID_CUSTOMIZE_VALIDATION         9062

// for Projects plug-in
#ifdef USE_PROJECTS_PLUGIN

#define SYMBOL_SORT_NONE						0
#define SYMBOL_SORT_CASE_SENSITIVE				1
#define SYMBOL_SORT_CASE_INSENSITIVE			2
#define SYMBOL_SORT_MASK						3
#define DEF_SYMBOL_SORT							SYMBOL_SORT_CASE_SENSITIVE
#define SYMBOL_REFRESH							4

#define PROJECTS_USER_MSG_OPEN_SOLUTION			0  // lParam: (LPCWSTR)szSolutionFile    open a solution file
#define PROJECTS_USER_MSG_CREATE_TAGS			1  // lParam: ignored     Start creating tags for the active file.  The return value might be E_NOT_READY when symbol file is not ready.
#define PROJECTS_USER_MSG_GET_SYMBOLS			2  // lParam: (GET_SYMBOLS_INFO*)pInfo   retrieves symbol list, and enumerate symbol with pInfo->pEnumSymbolProc function.  The return value might be E_NOT_READY when symbol file is not ready.
#define PROJECTS_USER_GO_TO_DEFINITION			3  // lParam: ignored     Go to Definition of the currenct cursor position.  The return value might be E_NOT_READY when symbol file is not ready.
#define PROJECTS_USER_POP_CURRENT_POS			4  // lParam: ignored     Pop Current Context
#define PROJECTS_USER_SHOW_PARAMETER_INFO		5  // lParam: ignored     Show Parameter Information.  The return value might be E_NOT_READY when symbol file is not ready.
#define PROJECTS_USER_GO_TO_DEFINITION_OF		6  // lParam: (LPCWSTR)pszSymbol   Go to Definition of the pszSymbol.  The return value might be E_NOT_READY when symbol file is not ready.
#define PROJECTS_USER_SYMBOL_LIST				7  // lParam: ignored     Toggle the user symbol list.
#define PROJECTS_USER_IS_SYMBOL_LIST_VISIBLE	8  // lParam: ignored     returns TRUE if the use symbol list is displayed, FALSE if not displayed.

#define E_NOT_READY	(-1)

/* This structure contains information about an extension field for a tag.
* These exist at the end of the tag in the form "key:value").
*/
typedef struct {

	/* the key of the extension field */
	const char *key;

	/* the value of the extension field (may be an empty string) */
	const char *value;

} TAG_EXTENSION_FIELD;

/* This structure contains information about a specific tag. */
typedef struct {

	/* name of tag */
	const char *name;

	/* path of source file containing definition of tag */
	const char *file;

	/* address for locating tag in source file */
	struct {
		/* pattern for locating source line
		* (may be NULL if not present) */
		const char *pattern;

		/* line number in source file of tag definition
		* (may be zero if not known) */
		unsigned long lineNumber;
	} address;

	/* kind of tag (may by name, character, or NULL if not known) */
	const char *kind;

	/* is tag of file-limited scope? */
	short fileScope;

	/* miscellaneous extension fields */
	struct {
		/* number of entries in `list' */
		unsigned short count;

		/* list of key value pairs */
		TAG_EXTENSION_FIELD *list;
	} fields;

} TAG_ENTRY;

typedef BOOL( CALLBACK* ENUM_SYMBOL_PROC )(TAG_ENTRY*, LPARAM);

typedef struct _GET_SYMBOLS_INFO {
	UINT_PTR			cbSize;
	UINT_PTR			nFlags;
	LPARAM				lParam;
	ENUM_SYMBOL_PROC	pEnumSymbolProc;
} GET_SYMBOLS_INFO;

#endif // USE_PROJECTS_PLUGIN
