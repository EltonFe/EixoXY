object Form2: TForm2
  Left = 0
  Top = 0
  Cursor = crCross
  Caption = 'Form2'
  ClientHeight = 961
  ClientWidth = 1784
  Color = clWhite
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Visible = True
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  PixelsPerInch = 400
  TextHeight = 13
  object Label1: TLabel
    Left = 1576
    Top = 304
    Width = 70
    Height = 19
    Caption = 'XYZ(0;0);'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 1176
    Top = 264
    Width = 54
    Height = 19
    Caption = 'Eixo Yo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 1700
    Top = 615
    Width = 53
    Height = 19
    Caption = 'Eixo Xo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label14: TLabel
    Left = 1198
    Top = 216
    Width = 73
    Height = 13
    Caption = 'GetLastError();'
  end
  object Panel10: TPanel
    Left = 0
    Top = 0
    Width = 1784
    Height = 177
    Align = alTop
    Caption = 'Panel10'
    TabOrder = 0
    object Button22: TButton
      Left = 673
      Top = 75
      Width = 136
      Height = 81
      Caption = 'Close'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button22Click
    end
    object Panel1: TPanel
      Left = 673
      Top = 8
      Width = 343
      Height = 61
      TabOrder = 1
      object RadioButton1: TRadioButton
        Left = 24
        Top = 22
        Width = 137
        Height = 17
        Caption = 'Linha'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 180
        Top = 22
        Width = 149
        Height = 17
        Caption = 'Cancela Linha'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        TabStop = True
      end
    end
    object Panel2: TPanel
      Left = 1353
      Top = 7
      Width = 181
      Height = 71
      TabOrder = 2
      object Label2: TLabel
        Left = 27
        Top = 9
        Width = 18
        Height = 19
        Caption = 'Zo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 55
        Top = 6
        Width = 121
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '0,0'
        OnDblClick = Edit1DblClick
      end
      object CheckBox1: TCheckBox
        Left = 37
        Top = 36
        Width = 97
        Height = 17
        Caption = 'Ativa'
        Checked = True
        State = cbChecked
        TabOrder = 1
        Visible = False
      end
    end
    object Panel3: TPanel
      Left = 1017
      Top = 7
      Width = 336
      Height = 61
      TabOrder = 3
      object RadioXoY: TRadioButton
        Left = 16
        Top = 22
        Width = 121
        Height = 17
        Caption = 'Eixo XoY'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = True
        OnClick = RadioXoYClick
      end
      object RadioZoX: TRadioButton
        Left = 181
        Top = 22
        Width = 116
        Height = 17
        Caption = 'Eixo ZoX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioZoXClick
      end
    end
    object Panel4: TPanel
      Left = 1017
      Top = 74
      Width = 336
      Height = 41
      Caption = 'Panel4'
      ShowCaption = False
      TabOrder = 4
      object RXoY: TRadioButton
        Left = 24
        Top = 11
        Width = 113
        Height = 17
        Caption = 'RXoY'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = RXoYClick
      end
      object RZoX: TRadioButton
        Left = 119
        Top = 11
        Width = 113
        Height = 17
        Caption = 'RZoX'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RZoXClick
      end
      object Cancel: TRadioButton
        Left = 226
        Top = 11
        Width = 87
        Height = 17
        Caption = 'Cancela'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        TabStop = True
      end
    end
    object Panel5: TPanel
      Left = 1353
      Top = 88
      Width = 181
      Height = 74
      Caption = 'Panel5'
      ShowCaption = False
      TabOrder = 5
      object Label4: TLabel
        Left = 26
        Top = 13
        Width = 19
        Height = 19
        Caption = 'Yo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit2: TEdit
        Left = 55
        Top = 13
        Width = 121
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '0,0'
      end
    end
    object Panel6: TPanel
      Left = 1017
      Top = 121
      Width = 336
      Height = 41
      TabOrder = 6
      object BetaT0: TRadioButton
        Left = 99
        Top = 8
        Width = 73
        Height = 17
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = BetaT0Click
      end
      object BetaTMPI2: TRadioButton
        Left = 24
        Top = 8
        Width = 74
        Height = 17
        Caption = 'PI/2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = BetaTMPI2Click
      end
      object RadioButton3: TRadioButton
        Left = 160
        Top = 8
        Width = 113
        Height = 17
        Caption = 'BetaT'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        TabStop = True
        OnClick = RadioButton3Click
      end
      object CheckBox2: TCheckBox
        Left = 232
        Top = 8
        Width = 89
        Height = 17
        Caption = 'Desenha'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object Panel7: TPanel
      Left = 398
      Top = 8
      Width = 269
      Height = 152
      Caption = 'Panel7'
      ShowCaption = False
      TabOrder = 7
      object Label7: TLabel
        Left = 126
        Top = 65
        Width = 113
        Height = 33
        Caption = '----|----'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -27
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label8: TLabel
        Left = 100
        Top = 49
        Width = 74
        Height = 18
        Caption = 'Veloc Inicial'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label13: TLabel
        Left = 100
        Top = 100
        Width = 43
        Height = 18
        Caption = 'Angulo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Button31: TButton
        Left = 0
        Top = 60
        Width = 86
        Height = 32
        Caption = '(-)Eixo Y'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button31Click
      end
      object Button32: TButton
        Left = 120
        Top = 5
        Width = 105
        Height = 35
        Caption = 'Lan'#231'ar'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button32Click
      end
      object Button33: TButton
        Left = 0
        Top = 19
        Width = 86
        Height = 33
        Caption = '(+)Eixo Z'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = Button33Click
      end
      object Button34: TButton
        Left = 0
        Top = 98
        Width = 86
        Height = 32
        Caption = '(-)Eixo X'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = Button34Click
      end
      object Edit6: TEdit
        Left = 197
        Top = 48
        Width = 65
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Text = '80'
        OnEnter = Edit6Enter
      end
      object Edit7: TEdit
        Left = 198
        Top = 98
        Width = 64
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Text = '45'
        OnEnter = Edit7Enter
      end
    end
    object Panel8: TPanel
      Left = 15
      Top = 7
      Width = 377
      Height = 153
      Caption = 'Panel8'
      ShowCaption = False
      TabOrder = 8
      object Button30: TButton
        Left = 0
        Top = 58
        Width = 145
        Height = 38
        Caption = '(-)HiperDown'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button30Click
      end
      object Button29: TButton
        Left = 0
        Top = 13
        Width = 145
        Height = 39
        Caption = '(+) HiperUP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button29Click
      end
      object Button24: TButton
        Left = 151
        Top = 13
        Width = 99
        Height = 39
        Caption = 'Alpha'
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = Button24Click
      end
      object ButtonRecupera: TButton
        Left = 256
        Top = 14
        Width = 97
        Height = 38
        Caption = 'Abrir '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = ButtonRecuperaClick
      end
      object Button25: TButton
        Left = 151
        Top = 64
        Width = 99
        Height = 39
        Caption = 'Beta'
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = Button25Click
      end
      object ButtonSalvar: TButton
        Left = 256
        Top = 58
        Width = 97
        Height = 38
        Caption = 'Salvar'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        OnClick = ButtonSalvarClick
      end
      object Button35: TButton
        Left = 151
        Top = 111
        Width = 99
        Height = 34
        Caption = 'Teta'
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        OnClick = Button35Click
      end
    end
    object Panel9: TPanel
      Left = 1534
      Top = 7
      Width = 250
      Height = 155
      Caption = 'Panel9'
      ShowCaption = False
      TabOrder = 9
      object Label3: TLabel
        Left = 162
        Top = 9
        Width = 18
        Height = 19
        Caption = 'Xo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 161
        Top = 42
        Width = 19
        Height = 19
        Caption = 'Yo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 162
        Top = 72
        Width = 18
        Height = 19
        Caption = 'Zo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 59
        Top = 107
        Width = 98
        Height = 19
        Caption = 'PXYZ{0;0;0};'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 59
        Top = 131
        Width = 98
        Height = 19
        Caption = 'PXYZ{0;0;0};'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit3: TEdit
        Left = 6
        Top = 6
        Width = 147
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '0,0'
      end
      object Edit4: TEdit
        Left = 5
        Top = 39
        Width = 147
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '0,0'
      end
      object Edit5: TEdit
        Left = 6
        Top = 71
        Width = 147
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '0,0'
      end
      object Button36: TButton
        Left = 13
        Top = 112
        Width = 35
        Height = 25
        Caption = 'XYZ'
        TabOrder = 3
        OnClick = Button36Click
      end
    end
    object Close: TButton
      Left = 870
      Top = 75
      Width = 141
      Height = 80
      Caption = 'Color'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ModalResult = 8
      ParentFont = False
      TabOrder = 10
      OnClick = CloseClick
    end
  end
  object ColorBox1: TColorBox
    Left = 15
    Top = 116
    Width = 145
    Height = 38
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 32
    ParentFont = False
    TabOrder = 1
  end
  object Timer1: TTimer
    Interval = 39
    OnTimer = Timer1Timer
    Left = 184
    Top = 424
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'desen'
    Filter = 'Desenhos Files (*.desen)|*.desen'
    Left = 568
    Top = 248
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Desenhos Files (*.desen)| *.desen'
    Left = 576
    Top = 336
  end
  object PopupMenu1: TPopupMenu
    Left = 736
    Top = 320
    object LimpaDesenho1: TMenuItem
      Caption = 'LimpaDesenho()'
      OnClick = LimpaDesenho1Click
    end
    object PontoaPonto1: TMenuItem
      Caption = 'Ponto a Ponto'
      OnClick = PontoaPonto1Click
    end
    object Form31: TMenuItem
      Caption = 'Anima'#231#227'o XYZ'
      OnClick = Form31Click
    end
    object ConstruoEIxoXYZ1: TMenuItem
      Caption = 'Constru'#231#227'o EIxo XYZ'
      OnClick = ConstruoEIxoXYZ1Click
    end
    object ConstruoElipse1: TMenuItem
      Caption = 'Constru'#231#227'o Elipse'
      OnClick = ConstruoElipse1Click
    end
    object Voltar1: TMenuItem
      Caption = 'VOLTAR Line'
      OnClick = Voltar1Click
    end
    object VoltarCirculo1: TMenuItem
      Caption = 'VOLTAR Circulo'
      OnClick = VoltarCirculo1Click
    end
  end
  object Timer2: TTimer
    Interval = 60
    OnTimer = Timer2Timer
    Left = 544
    Top = 528
  end
  object Timer3: TTimer
    Interval = 10
    OnTimer = Timer3Timer
    Left = 336
    Top = 416
  end
end
