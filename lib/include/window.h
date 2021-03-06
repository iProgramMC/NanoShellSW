#ifndef _WINDOW_H
#define _WINDOW_H

#include "nanoshell.h"
#include "video.h"

#define RECT(rect,x,y,w,h) do {\
	rect.left = x, rect.top = y, rect.right = x+w, rect.bottom = y+h;\
} while (0)

#define TITLE_BAR_HEIGHT 18
#define WINDOW_RIGHT_SIDE_THICKNESS 0
#define EVENT_QUEUE_MAX 256
#define WINDOW_TITLE_MAX 250

#define BACKGROUND_COLOR 0xFF007F7F
#define BUTTON_MIDDLE_COLOR 0xFFCCCCCC
#define WINDOW_BACKGD_COLOR 0xFFAAAAAA
#define WINDOW_EDGE_COLOR 0xFF000000
#define WINDOW_TITLE_ACTIVE_COLOR 0xFF00007F
#define WINDOW_TITLE_INACTIVE_COLOR 0xFF7F7F7F
#define WINDOW_TITLE_ACTIVE_COLOR_B 0xFF0000FF
#define WINDOW_TITLE_INACTIVE_COLOR_B 0xFFAAAAAA
#define WINDOW_TITLE_TEXT_COLOR_SHADOW 0xFF00003F
#define WINDOW_TITLE_TEXT_COLOR 0x00FFFFFF

// This flag tells the operating system that it may choose where to place a window.
// If the xPos and yPos are bigger than or equal to zero, the application tells the OS where it should place the window.
// The OS will use this as a guideline, for example, if an application wants to go off the screen, the OS
// will reposition its window to be fully inside the screen boundaries.
#define CW_AUTOPOSITION   (-1)

//WORK: Add in your icons here in this enum:
enum 
{
	ICON_NULL,
	ICON_CABINET,
	ICON_CHIP,
	ICON_CHIP_SQ,
	ICON_COMPUTER,
	ICON_COMPUTER_SHUTDOWN,
	ICON_DESKTOP,
	ICON_DRAW,
	ICON_EARTH,
	ICON_ERROR,
	ICON_EXECUTE_FILE,
	ICON_FILE,
	ICON_FILES,
	ICON_FOLDER,
	ICON_FOLDER_BLANK,
	ICON_FOLDER_MOVE,
	ICON_FOLDER_PARENT,
	ICON_FOLDER16_CLOSED,
	ICON_FOLDER16_OPEN,
	ICON_GLOBE,
	ICON_GO,
	ICON_HAND,
	ICON_HELP,
	ICON_INFO,
	ICON_KEYBOARD,
	ICON_KEYBOARD2,
	ICON_LAPTOP,
	ICON_NOTES,
	ICON_PAINT,
	ICON_SERIAL,
	ICON_STOP,
	ICON_TEXT_FILE,
	ICON_WARNING,
	ICON_NANOSHELL_LETTERS,
	ICON_NANOSHELL_LETTERS16,
	ICON_NANOSHELL,
	ICON_NANOSHELL16,
	ICON_BOMB,
	ICON_BOMB_SPIKEY,
	ICON_FILE16,
	ICON_TEXT_FILE16,
	ICON_EXECUTE_FILE16,
	ICON_FOLDER_PARENT16,
	//icons V1.1
	ICON_FOLDER_SETTINGS,
	ICON_CABINET16,
	ICON_COMPUTER16,
	ICON_COMMAND,
	ICON_COMMAND16,
	ICON_ERROR16,
	//icons V1.2
	ICON_LOCK,
	ICON_DIRECTIONS,
	ICON_CERTIFICATE,
	ICON_FILE_WRITE,
	ICON_SCRAP_FILE,
	ICON_SCRAP_FILE16,
	ICON_RESMON,
	ICON_BILLBOARD,
	ICON_FILE_CSCRIPT,
	ICON_FILE_CSCRIPT16,
	ICON_FILE_CLICK,
	ICON_KEYS,
	ICON_RESTRICTED,
	ICON_HOME,
	ICON_HOME16,
	ICON_ADAPTER,
	ICON_CLOCK,
	ICON_CLOCK16,
	//icons V1.3
	ICON_APPLICATION,
	ICON_APPLICATION16,
	ICON_TASKBAR,
	ICON_APP_DEMO,
	ICON_COMPUTER_FLAT,
	ICON_CALCULATOR,
	ICON_CALCULATOR16,
	ICON_DESKTOP2,
	ICON_MOUSE,
    //Icons V1.31
	ICON_AMBULANCE,
	//icons V1.32
	ICON_FONTS,
	ICON_FONTS16,
	//icons V1.33
	ICON_RESMON16,
	ICON_NOTES16,
	ICON_FILE_NANO,
	//icons V1.34
	ICON_CLOCK_EMPTY,//Special case which draws more stuff
	ICON_COUNT
};

enum {
	EVENT_NULL,
	EVENT_CREATE,
	EVENT_DESTROY,
	EVENT_PAINT,
	EVENT_MOVE,
	EVENT_SIZE,
	EVENT_ACTIVATE,
	EVENT_SETFOCUS,
	EVENT_KILLFOCUS,
	EVENT_UPDATE,
	EVENT_MOVECURSOR,
	EVENT_CLICKCURSOR,
	EVENT_RELEASECURSOR,
	EVENT_COMMAND,
	EVENT_CLOSE,
	EVENT_KEYPRESS,
	EVENT_KEYRAW,
	EVENT_MINIMIZE,//do not call this normally.
	EVENT_UNMINIMIZE,
	EVENT_MAX
};
enum {
	//A null control.  Does nothing.
	CONTROL_NONE,
	//A text control printing text in its top-left corner.
	CONTROL_TEXT,
	//A control displaying an icon in the center of the rectangle.
	CONTROL_ICON,
	//A clickable button which triggers an EVENT_COMMAND with its comboID
	//as its first parm.
	CONTROL_BUTTON,
	//A text input field.  Not Finished
	CONTROL_TEXTINPUT,
	//A checkbox.  Not Finished.
	CONTROL_CHECKBOX,
	//A clickable label, which renders its text in the center-left.
	//Does the same as the CONTROL_BUTTON.
	CONTROL_CLICKLABEL,
	//A text control printing text in the center of the rectangle.
	CONTROL_TEXTCENTER,
	//A clickable button which triggers an event based on this->m_parm1
	//with its comboID as its first parm.
	CONTROL_BUTTON_EVENT,
	//A list view.  Complicated.
	CONTROL_LISTVIEW,
	//A vertical scroll bar.
	CONTROL_VSCROLLBAR,
	//A horizontal scroll bar.
	CONTROL_HSCROLLBAR,
	//A menu bar attached to the top of a window.
	//Adding more than one control is considered UB
	CONTROL_MENUBAR,
	//A text control printing big text (>127 chars)
	CONTROL_TEXTHUGE,
	//Same as CONTROL_LISTVIEW but with bigger icons.
	CONTROL_ICONVIEW,
	//Does nothing except surround other controls with a rectangle.  Useful for grouping settings.
	CONTROL_SURROUND_RECT,
	//This control is purely to identify how many controls we support
	//currently.  This control is unsupported and will crash your application
	//if you use this.
	CONTROL_COUNT
};

enum
{
	MBID_OK = 0x10010,
	MBID_CANCEL,
	MBID_ABORT,
	MBID_RETRY,
	MBID_IGNORE,
	MBID_YES,
	MBID_NO,
	MBID_TRY_AGAIN,
	MBID_CONTINUE,
	MBID_COUNT,
};

#define MB_OK                 0x00000000 //The message box contains one push button: OK.  This is the default.
#define MB_OKCANCEL           0x00000001 //The message box contains two push buttons: OK and Cancel.
#define MB_ABORTRETRYIGNORE   0x00000002 //The message box contains three push buttons: Abort, Retry and Ignore.
#define MB_YESNOCANCEL        0x00000003 //The message box contains three push buttons: Yes, No, and Cancel.
#define MB_YESNO              0x00000004 //The message box contains two push buttons: Yes, and No.
#define MB_RETRYCANCEL        0x00000005 //The message box contains two push buttons: Retry and Cancel.
#define MB_CANCELTRYCONTINUE  0x00000006 //The message box contains three push buttons: Cancel, Retry, and Continue.
#define MB_RESTART            0x00000007 //The message box contains one push button: Restart.

struct WindowStruct;
struct ControlStruct;
typedef void (*WidgetEventHandler) (struct ControlStruct*, int eventType, int parm1, int parm2, struct WindowStruct* parentWindow);
typedef void (*WindowProc)         (struct WindowStruct*, int, int, int);

typedef struct
{
	int  m_icon;//can be blank
	char m_contents [128];
}
ListItem;

#define LIST_ITEM_HEIGHT 16

typedef struct
{
	bool m_hasIcons;
	int  m_elementCount, m_capacity;
	int  m_scrollY;
	int  m_highlightedElementIdx;
	ListItem *m_pItems;
}
ListViewData;

typedef struct
{
	bool m_isBeingDragged, m_clickedBefore;
	bool m_yMinButton, m_yMaxButton;
	int  m_min, m_max, m_pos, m_dbi;
}
ScrollBarData;

typedef struct
{
	bool m_clicked;
}
ButtonData;

typedef struct tagMenuBarTreeItem
{
	int  m_comboID;//can be searchable
	int  m_childrenCount,
	     m_childrenCapacity;//if childrenCount reaches this and we need to add another, double this
	struct tagMenuBarTreeItem* m_childrenArray;
	char m_text [104];
	//if this value is set, it gets drawn if this is an item part of the root tree, or the parent is open too.
	bool m_isOpen;
}
MenuBarTreeItem;

typedef struct
{
	MenuBarTreeItem m_root;
}
MenuBarData;

typedef struct
{
	bool  m_focused;
	bool  m_onlyOneLine, m_showLineNumbers;//note that these are mutually exclusive, but both can be turned off
	int   m_textCapacity, m_textLength;//The text length needs to be 1 less than the text capacity.
	                                   //If the text capacity is 65, for example, the textLength may not be bigger than 64.
	int   m_textCursorIndex, m_textCursorSelStart, m_textCursorSelEnd,
	      m_scrollY;
	char* m_pText;
}
TextInputData;

typedef struct ControlStruct
{
	bool      m_active;
	int       m_type;//CONTROL_XXX
	int       m_parm1, m_parm2;
	int       m_comboID;
	char      m_text[128];
	void*     m_dataPtr;
	Rectangle m_rect;
	bool      m_bMarkedForDeletion;
	
	//data for controls:
	union
	{
		ListViewData  m_listViewData;
		ScrollBarData m_scrollBarData;
		ButtonData    m_buttonData;
		MenuBarData   m_menuBarData;
		TextInputData m_textInputData;
	};
	
	//event handler
	WidgetEventHandler OnEvent;
}
Control;

#define WF_NOCLOSE  0x00000001
#define WF_FROZEN   0x00000002
#define WF_NOTITLE  0x00000004
#define WF_NOBORDER 0x00000008

typedef struct WindowStruct
{
	bool       m_used;
	bool       m_minimized;
	bool       m_hidden;
	bool       m_isBeingDragged;
	bool       m_isSelected;
	
	bool       m_renderFinished;
	
	char       m_title [250];
	
	int 	   m_flags;
	
	WindowProc m_callback;
	Rectangle  m_rect;
	Rectangle  m_rectBackup;
	//uint32_t*  m_framebuffer;
	//int        m_fbWidth, m_fbHeight;
	VBEData    m_vbeData;
	
	int        m_iconID;
	
	bool       m_eventQueueLock;
	short      m_eventQueue[EVENT_QUEUE_MAX];
	int        m_eventQueueParm1[EVENT_QUEUE_MAX];
	int        m_eventQueueParm2[EVENT_QUEUE_MAX];
	int        m_eventQueueSize;
	
	bool       m_markedForDeletion;
	
	Control*   m_pControlArray;
	int        m_controlArrayLen;
	
	void*      m_data; //user data
	
	//currently void because we don't have Task defined yet
	void      *m_pOwnerThread, 
	          *m_pSubThread;//in case you ever want to use this
	
	void*      m_consoleToFocusKeyInputsTo; //currently void because we don't have Console defined yet
} Window;

#define CALLBACK 

#define MAKE_MOUSE_PARM(x, y) ((x)<<16|(y))
#define GET_X_PARM(parm1)  (parm1>>16)
#define GET_Y_PARM(parm1)  (parm1&0xFFFF)

/**
 * Creates a window, with its top left corner at (xPos, yPos), and its
 * bottom right corner at (xPos + xSize, yPos + ySize).
 *
 * WindowProc is the main event handler of the program, but it isn't called.
 * spontaneously. Instead, you use it like:
 *
 * while (HandleMessages(pWindow));
 */
Window* CreateWindow (const char* title, int xPos, int yPos, int xSize, int ySize, WindowProc proc, int flags);

/**
 * Updates the window, and handles its messages.
 */
bool HandleMessages(Window* pWindow);

/**
 * The default window event procedure.  Call this when you don't know
 * how to handle an event properly.
 */
void DefaultWindowProc (Window* pWindow, int messageType, int parm1, int parm2);

/**
 * Requests a safe window destruction from the window manager.
 */
void DestroyWindow (Window* pWindow);

/**
 * Displays a modal dialog box that contains a system icon, a set of buttons, and 
 * a brief application-specific message, such as status or error information.  The message
 * box returns an integer value that indicates which button the user clicked.
 */
int MessageBox (Window* pWindow, const char* pText, const char* pCaption, uint32_t type);

/**
 * Adds a control to the window.
 */
int AddControl(Window* pWindow, int type, Rectangle rect, const char* text, int comboID, int p1, int p2);

/**
 * Sets the minimum value for a SCROLLBAR control with a certain comboID.
 */
void SetScrollBarMin (Window *pWindow, int comboID, int min);

/**
 * Sets the maximum value for a SCROLLBAR control with a certain comboID.
 */
void SetScrollBarMax (Window *pWindow, int comboID, int max);

/**
 * Sets the current progress value for a SCROLLBAR control with a certain comboID.
 */
void SetScrollBarPos (Window *pWindow, int comboID, int pos);

/**
 * Gets the current progress value for a SCROLLBAR control with a certain comboID.
 */
int GetScrollBarPos (Window *pWindow, int comboID);

/**
 * Adds an element to a ListView component with a certain comboID.
 */
void AddElementToList (Window* pWindow, int comboID, const char* pText, int optionalIcon);

/**
 * Gets an element's string contents from a ListView component with a certain comboID.
 */
const char* GetElementStringFromList (Window* pWindow, int comboID, int index);

/**
 * Removes an element from a ListView component with a certain comboID.
 */
void RemoveElementFromList (Window* pWindow, int comboID, int elemIndex);

/**
 * Clears the items from a ListView component with a certain comboID.
 */
void ResetList (Window* pWindow, int comboID);

/**
 * Changes the text of any component with text with a certain comboID.
 */
void SetLabelText (Window *pWindow, int comboID, const char* pText);

/**
 * Works on the control with the comboID of 'menuBarControlId'.
 * To that control, it adds a menu item with the comboID of 'comboIdAs' to the menu item with the comboID of 'comboIdTo'.
 */
void AddMenuBarItem (Window* pWindow, int menuBarControlId, int comboIdTo, int comboIdAs, const char* pText);

/**
 * Changes the text of a TEXTHUGE with text with a certain comboID.
 */
void SetHugeLabelText (Window *pWindow, int comboID, const char* pText);

/**
 * Changes the text of a TEXTINPUT with text with a certain comboID.
 */
void SetTextInputText(Window* pWindow, int comboID, const char* pText);

/**
 * Changes the icon of a window, displayed when minimized.
 */
void SetWindowIcon (Window* pWindow, int icon);

/**
 * Changes the icon of an ICON control, or the internal parm1 of any other control.
 */
void SetIcon (Window* pWindow, int comboID, int icon);

/**
 * Changes the text of a window.
 */
void SetWindowTitle(Window* pWindow, const char* pTitle);

/**
 * Queues up an event to the window.
 */
void RegisterEvent(Window* pWindow, short evType, int parm1, int parm2);
void RegisterEventInsideWndProc(Window* pWindow, short evType, int parm1, int parm2);

#endif//_WINDOW_H
