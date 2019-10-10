object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Anima'#231#227'o XYZ'
  ClientHeight = 684
  ClientWidth = 1115
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 168
    Top = 104
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Panel1: TPanel
    Left = 257
    Top = 10
    Width = 501
    Height = 123
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 0
    object CheckBox1: TCheckBox
      Left = 6
      Top = 12
      Width = 83
      Height = 17
      Caption = 'Alpha'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 6
      Top = 45
      Width = 90
      Height = 17
      Caption = 'Beta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 6
      Top = 80
      Width = 86
      Height = 17
      Caption = 'Teta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Panel2: TPanel
      Left = 96
      Top = 3
      Width = 258
      Height = 32
      Caption = 'Panel2'
      ShowCaption = False
      TabOrder = 3
      object RadioButton1: TRadioButton
        Left = 8
        Top = 6
        Width = 98
        Height = 17
        Caption = 'Horario'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 112
        Top = 6
        Width = 147
        Height = 17
        Caption = 'Anti-Hor'#225'rio'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton2Click
      end
    end
    object Panel3: TPanel
      Left = 96
      Top = 42
      Width = 258
      Height = 32
      Caption = 'Panel2'
      ShowCaption = False
      TabOrder = 4
      object RadioButton3: TRadioButton
        Left = 7
        Top = 3
        Width = 106
        Height = 17
        Caption = 'Horario'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton3Click
      end
      object RadioButton4: TRadioButton
        Left = 112
        Top = 3
        Width = 146
        Height = 17
        Caption = 'Anti-Hor'#225'rio'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton4Click
      end
    end
    object Panel4: TPanel
      Left = 97
      Top = 76
      Width = 258
      Height = 35
      Caption = 'Panel2'
      ShowCaption = False
      TabOrder = 5
      object RadioButton5: TRadioButton
        Left = 6
        Top = 4
        Width = 100
        Height = 17
        Caption = 'Horario'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton5Click
      end
      object RadioButton6: TRadioButton
        Left = 112
        Top = 7
        Width = 146
        Height = 17
        Caption = 'Anti-Ho'#225'rio'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton6Click
      end
    end
    object Button2: TButton
      Left = 360
      Top = 5
      Width = 130
      Height = 32
      Caption = 'Aumenta Alpha'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 361
      Top = 41
      Width = 129
      Height = 31
      Caption = 'Aumenta Beta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 361
      Top = 76
      Width = 129
      Height = 32
      Caption = 'Aumenta Teta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = Button4Click
    end
  end
  object Button5: TButton
    Left = 320
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 1
    OnClick = Button5Click
  end
  object Panel5: TPanel
    Left = 3
    Top = 4
    Width = 242
    Height = 137
    Caption = 'Panel5'
    TabOrder = 2
    object Button1: TButton
      Left = 28
      Top = 16
      Width = 177
      Height = 99
      Caption = 'Open'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 888
    Top = 24
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 744
    Top = 24
  end
  object Timer2: TTimer
    Interval = 150
    OnTimer = Timer2Timer
    Left = 776
    Top = 24
  end
  object Timer3: TTimer
    Interval = 150
    OnTimer = Timer3Timer
    Left = 808
    Top = 24
  end
  object Timer4: TTimer
    Interval = 150
    OnTimer = Timer4Timer
    Left = 840
    Top = 24
  end
end
