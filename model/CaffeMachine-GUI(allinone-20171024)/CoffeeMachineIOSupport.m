function handle = CoffeeMachineIOSupport(method, varargin)

persistent AmericanCoffeeState;
persistent CoffeeLatteState;
persistent CappuccinoState;
persistent TakeOutEvent;
global fig;
global axes;
global sideline;
global waterploy;
global coffeeploy;
global milkploy;
global sugarploy;
global watertext;
global coffeetext;
global milktext;
global sugartext;

if isempty(AmericanCoffeeState)
    AmericanCoffeeState = 0;
end
if isempty(CoffeeLatteState)
    CoffeeLatteState = 0;
end
if isempty(CappuccinoState)
    CappuccinoState = 0;
end
if isempty(TakeOutEvent)
    TakeOutEvent = 0;
end
if nargin < 1
    return
end

if isnumeric(method)
    Coffee = method(2:end);
    method = method(1);
    switch method
        case 0
            handle = AmericanCoffeeState;
        case 1
            handle = CoffeeLatteState;
        case 2
            handle = CappuccinoState;
        case 3
            handle = TakeOutEvent;
        case 4
            handle = 1;
            if (isempty(sideline) || ~ishandle(sideline))
                fig_init;
                return
            end
            % set(state, 'String', sprintf('Cup %d\nWater %d(%d¡ãC)\nCoffee %d\nMilk %d\nSugar %d\n', Coffee(1), Coffee(2), Coffee(3), Coffee(4), Coffee(5), Coffee(6)));
            if Coffee(1) == 0
                set(sideline, 'Visible', 'off');
                set(waterploy, 'Visible', 'off');
                set(coffeeploy, 'Visible', 'off');
                set(milkploy, 'Visible', 'off');
                set(sugarploy, 'Visible', 'off');
                set(watertext, 'Visible', 'off');
                set(coffeetext, 'Visible', 'off');
                set(milktext, 'Visible', 'off');
                set(sugartext, 'Visible', 'off');
            else
                water = Coffee(2);
                watertemp = Coffee(3);
                coffee = Coffee(4);
                milk = Coffee(5);
                sugar = Coffee(6);
                all = water + coffee + milk + sugar;
                now = 0;
                next = now + water;
                set(waterploy, 'XData', [0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                               'YData', [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all]);
                set(watertext, 'Position', [0.5, 0.1 + 0.8 * (next + now) / 2 / all], 'String', sprintf('Water: %.2fml(%.2f¡ãC)', water, watertemp));
                now = next;
                next = now + coffee;
                set(coffeeploy, 'XData', [0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                                   'YData', [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all]);
                set(coffeetext, 'Position', [0.5, 0.1 + 0.8 * (next + now) / 2 / all], 'String', sprintf('Coffee: %.2fml', coffee));
                now = next;
                next = now + milk;
                set(milkploy, 'XData', [0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                                 'YData', [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all]);
                set(milktext, 'Position', [0.5, 0.1 + 0.8 * (next + now) / 2 / all], 'String', sprintf('Milk: %.2fml', milk));
                now = next;
                next = now + sugar;
                set(sugarploy, 'XData', [0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                                  'YData', [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all]);
                set(sugartext, 'Position', [0.5, 0.1 + 0.8 * (next + now) / 2 / all], 'String', sprintf('Sugar: %.2fml', sugar));
                
                set(sideline, 'Visible', 'on');
                set(waterploy, 'Visible', 'on');
                set(coffeeploy, 'Visible', 'on');
                set(milkploy, 'Visible', 'on');
                set(sugarploy, 'Visible', 'on');
                if (water > 0) 
                    set(watertext, 'Visible', 'on'); 
                end
                if (coffee > 0) 
                    set(coffeetext, 'Visible', 'on'); 
                end
                if (milk > 0) 
                    set(milktext, 'Visible', 'on'); 
                end
                if (sugar > 0) 
                    set(sugartext, 'Visible', 'on'); 
                end
            end
        otherwise
            error('undefine input');
    end
else
    switch method
        case 'init'
            fig_init;
            handle = 0;
        case 'displaycoffee'
            fig_drawcoffee;
            handle = 0;
        case 'AmericanCoffeeBtnDown'
            AmericanCoffeeState = 1;
            pause(0.5);
            AmericanCoffeeState = 0;
        case 'CoffeeLatteeBtnDown'
            CoffeeLatteState = 1;
            pause(0.5);
            CoffeeLatteState = 0;
        case 'CappuccinoBtnDown'
            CappuccinoState = 1;
            pause(0.5);
            CappuccinoState = 0;
        case 'TakeOutBtnDown'
            TakeOutEvent = 1;
            pause(0.5);
            TakeOutEvent = 0;
        case 'closefig'
            fig_close;
        otherwise
            error('undefine input');
    end
end

function fig_init
global fig;
if ishandle(fig)
    return;
end;
% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       'CoffeeMachineGUI', ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @CoffeeMachineIOSupport_OpeningFcn, ...
                   'gui_OutputFcn',  @CoffeeMachineIOSupport_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);

gui_mainfcn(gui_State);
% End initialization code - DO NOT EDIT
set_param('AllinOne','StopFcn',sprintf('CoffeeMachineIOSupport(''closefig'');'));

function fig_close
global fig;
if ishandle(fig)
    delete(fig);
end;

function CoffeeMachineIOSupport_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to CoffeeMachineGUI (see VARARGIN)

% Choose default command line output for CoffeeMachineGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes CoffeeMachineGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);
global fig;
global axes;
global state;
global sideline;
global waterploy;
global coffeeploy;
global milkploy;
global sugarploy;
global watertext;
global coffeetext;
global milktext;
global sugartext;
fig = hObject;
axes = findobj('Type', 'axes');
axis(axes, [0, 1, 0, 1]);
sideline = line([0.1, 0.2, 0.8, 0.9], [0.9, 0.1, 0.1, 0.9], 'Parent', axes, 'Color', 'k', 'Visible', 'off');
water = 100;
coffee = 20;
milk = 20;
sugar = 20;
all = water + coffee + milk + sugar;
now = 0;
next = now + water;
waterploy = line([0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                 [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all], 'Parent', axes, 'Color', 'k', 'Visible', 'off');
now = next;
next = now + coffee;
coffeeploy = patch([0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                   [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all], [96, 56, 17] ./ 256, 'Parent', axes, 'Visible', 'off');
now = next;
next = now + milk;
milkploy = patch([0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                 [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all], 'w', 'Parent', axes, 'Visible', 'off');
now = next;
next = now + sugar;
sugarploy = patch([0.2 - 0.1 * next / all, 0.2 - 0.1 * now / all, 0.8 + 0.1 * now / all, 0.8 + 0.1 * next / all], ...
                  [0.1 + 0.8 * next / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * now / all, 0.1 + 0.8 * next / all], [255, 255, 153] ./ 256, 'Parent', axes, 'Visible', 'off');
now = 0;
next = now + water;
watertext = text(0.5, 0.1 + 0.8 * (next + now) / 2 / all, 'water', 'Parent', axes, 'HorizontalAlignment', 'center', 'Visible', 'off');
now = next;
next = now + coffee;
coffeetext = text(0.5, 0.1 + 0.8 * (next + now) / 2 / all, 'coffee', 'Parent', axes, 'HorizontalAlignment', 'center', 'Color', 'w', 'Visible', 'off');
now = next;
next = now + milk;
milktext = text(0.5, 0.1 + 0.8 * (next + now) / 2 / all, 'milk', 'Parent', axes, 'HorizontalAlignment', 'center', 'Visible', 'off');
now = next;
next = now + sugar;
sugartext = text(0.5, 0.1 + 0.8 * (next + now) / 2 / all, 'sugar', 'Parent', axes, 'HorizontalAlignment', 'center', 'Visible', 'off');

% --- Outputs from this function are returned to the command line.
function varargout = CoffeeMachineIOSupport_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;